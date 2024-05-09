import subprocess
import pytest
import pathlib


@pytest.mark.parametrize(
    "input_data,expectation",
    [
        (
            b"""3 2
1 2
1 3""",
            b"YES",
        ),
        (
            b"""3 2
1 2
2 3""",
            b"YES",
        ),
        (
            b"""4 3
1 2
2 3
3 1""",
            b"NO",
        ),
        (
            b"""4 3
2 3
3 4
4 2""",
            b"NO",
        ),
    ],
)
def test_main(input_data: bytes, expectation: bytes):
    target = pathlib.Path(__file__).parent.parent.resolve() / pathlib.Path("a.out")
    process = subprocess.Popen(target, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output_data, err = process.communicate(input_data, timeout=1)
    assert err is None
    assert process.returncode == 0
    assert output_data.decode().strip() == expectation.decode()

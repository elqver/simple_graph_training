import subprocess
import pytest
import pathlib


@pytest.mark.parametrize(
    "input_data,expectation",
    [
        (
            b"""4 3
1 2
2 3
1 3""",
            b"NO",
        ),
        (
            b"""6 9
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6""",
            b"""YES
1 2 3""",
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

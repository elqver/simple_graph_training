import subprocess
import pytest
import pathlib


@pytest.mark.parametrize(
    "input_data,expectation",
    [
        (
            b"""6 5
4 3
3 2
4 1
1 5
5 2""",
            b"2",
        )
    ],
)
def test_main(input_data: bytes, expectation: bytes):
    target = pathlib.Path(__file__).parent.parent.resolve() / pathlib.Path("a.out")
    process = subprocess.Popen(target, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output_data, err = process.communicate(input_data, timeout=1)
    assert err is None
    assert process.returncode == 0
    assert output_data.decode().strip() == expectation.decode()

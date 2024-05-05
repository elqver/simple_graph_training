import subprocess
import pytest
import pathlib


@pytest.mark.parametrize(
    "input_data,expectation",
    [
        (
            b"""5 10
1 2
1 3
1 5
2 3
2 5
4 1
4 2
4 3
4 5
5 3""",
            b"YES",
        ),
    ],
)
def test_main(input_data: bytes, expectation: bytes):
    target = pathlib.Path(__file__).parent.parent.resolve() / pathlib.Path("a.out")
    process = subprocess.Popen(target, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output_data, _ = process.communicate(input_data)
    assert output_data.decode().strip() == expectation.decode()
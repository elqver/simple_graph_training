import subprocess
import pytest
import pathlib


@pytest.mark.parametrize(
    "input_data,expectation",
    [
        (
            b"""\
        5
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        1 1 1 1 1
        """,
            b"5",
        ),
        (
            b"""\
        1
        1
        """,
            b"1",
        ),
        (
            b"""\
        3
        1 0 1
        0 1 0
        1 0 0
        """,
            b"2",
        ),
        (
            b"""\
        5
        1 1 1 1 0
        1 0 1 1 1
        1 1 0 1 1
        1 1 1 1 1
        0 1 1 1 0
        """,
            b"2",
        ),
    ],
)
def test_main(input_data: bytes, expectation: bytes):
    target = pathlib.Path(__file__).parent.parent.resolve() / pathlib.Path("a.out")
    print(f"{target=}")
    process = subprocess.Popen(target, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    output_data, _ = process.communicate(input_data)
    assert output_data.decode().strip() == expectation.decode()

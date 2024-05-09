from invoke import task
import glob
import pytest


@task
def clean(ctx):
    print("CLEAN")
    objs = glob.glob("*.o")
    for obj in objs:
        print(f"{obj=}")
        ctx.run(f"rm -f {obj}")
    ctx.run("rm -f a.out")


@task(clean)
def compile(ctx):
    print("COMPILE")
    sources = glob.glob("*.cpp")
    for source in sources:
        object_file = source.replace(".cpp", ".o")
        ctx.run(f"g++ -c {source} -o {object_file}")


@task(compile)
def link(ctx):
    print("LINK")
    object_files = glob.glob("*.o")
    ctx.run(f"g++ {' '.join(object_files)} -o a.out")


@task(link, default=True)
def rut_tests(_):
    pytest.main(["-qq"])

import os

def check_exists(path):
    if (os.path.exists(path)):
        print(f"[S] {path} exists")
    else:
        print(f"[F] {path} not exists")
        exit(1)

def run_qemu(qemu, order, drives):
    cmdline = f"{qemu} -boot order={order}"
    for drive in drives:
        cmdline += f" -drive format=raw,file={drive}"
    print("Booting!")
    print(f"[debug] cmdline = '{cmdline}'")
    os.system(cmdline)

import sys

fdrive = sys.argv[1]
qemu = "/bin/qemu-system-x86_64"
bootorder = "ca"

for disk in sys.argv[1:]:
    check_exists(disk)

run_qemu(qemu, bootorder, sys.argv[1:])

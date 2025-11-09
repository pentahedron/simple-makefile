# Simple Makefile Example Project

This is a minimal C++ project demonstrating how to use [raylib](https://www.raylib.com/) with a simple setup on Windows using a custom Makefile.

---

## Project Structure

```markdown
project/
├── Makefile
├── src/
│ └── main.cpp
└── README.md
```

```markdown

- `src/main.cpp` – Main source file with a simple Raylib example.
- `Makefile` – Build instructions for compiling and linking with Raylib.
- `README.md` – Project documentation.

---

```

## Prerequisites

- [raylib](https://www.raylib.com/) installed (tested with 64-bit Windows version)
- g++ compiler (MinGW recommended)
- Make utility (comes with Git Bash, MSYS2, or MinGW)

Make sure raylib is installed in a folder such as `C:/raylib64` and adjust the paths in the Makefile if needed:

```makefile
CFLAGS = -I"C:/raylib64/include"
LDFLAGS = -L"C:/raylib64/lib" -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Open a terminal in the project root directory and run:

```bash
make
```
This will compile src/main.cpp and generate the executable main.exe.

### After building, run:

```bash
make run
```
This will execute the compiled program.

### To remove the compiled executable:

```bash
make clean
```
This will delete main.exe.

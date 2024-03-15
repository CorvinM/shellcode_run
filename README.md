# Shellcode Run

## Introduction

Shellcode Run is a cross-platform utility designed to execute flat binary shellcode files effortlessly. This tool simplifies the process of running and testing shellcode, making it accessible to security researchers, penetration testers, and developers working on low-level system tasks. Shellcode Run is built to work across various platforms, including Windows, and Linux.

## Usage

Using Shellcode Run is intuitive. Simply follow the syntax:

```
./sc_run shellcode.bin
```

Replace `shellcode.bin` with the path to your flat binary shellcode file.

## Installation

To use Shellcode Run, follow these steps:

1. Clone the repository:

```
git clone https://github.com/your_username/shellcode_run.git
```

2. Navigate to the cloned directory:

```
cd shellcode_run
```

3. Compile the source code:

```
mkdir build
cd build
cmake ..
cmake --build .
```

4. Run the utility with your shellcode file:

```
./sc_run path/to/your/shellcode.bin
```

## Examples

Here's an example demonstrating the usage of Shellcode Run:

```bash
./sc_run ../test/sc_hw_linux_x86_64.bin
```

This command executes the provided shellcode file, which in this case is a 64-bit linux "hello shellcode" program.

## Contributions

Contributions to Shellcode Run are welcome! If you encounter any bugs, have feature requests, or want to contribute improvements, feel free to open an issue or submit a pull request on GitHub.

## License

Shellcode Run is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute this software according to the terms of the license.
# raw
A macOS/ARM64 shell built with raw XNU system calls.

### Features
- **Zero Libraries/Dependencies**: Does not use LibC or standard headers.
- **Direct Syscalls**: Communicates directly with the XNU kernel.

### Build
```bash
make
./raw

type u64 = integer<64, false>;

// from libc
fn malloc(size: u64) -> &void;
fn free(ptr: &void);

type Tape = struct {
  cells: &bool,
  buffer: &bool,
  length: u64
};

fn tape_new(tape: &Tape, length: u64) {
  tape.length = length;
  tape.cells = malloc(tape.length * sizeof(u64));
  tape.buffer = malloc(tape.length * sizeof(u64));
}

fn tape_delete(tape: &Tape) {
  free(tape.cells);
  free(tape.buffer);
  tape.cells = nullptr;
  tape.buffer = nullptr;
  tape.length = 0;
}

fn tape_update(tape: &Tape) {
  // writes new state to buffer
  let end: u64 = tape.length - 1;
  for (let i: u64 = 1; i < end; i = i + 1) {
    let a: bool = *(tape.cells + i - 1);
    let b: bool = *(tape.cells + i);
    let c: bool = *(tape.cells + i + 1);
    if (a == 0) {
      if (b == 0) {
        if (c == 0) {
          *(tape.buffer + i) = 0;
        } else {
          *(tape.buffer + i) = 1;
        }
      } else {
        if (c == 0) {
          *(tape.buffer + i) = 1;
        } else {
          *(tape.buffer + i) = 1;
        }
      }
    } else {
      if (b == 0) {
        if (c == 0) {
          *(tape.buffer + i) = 0;
        } else {
          *(tape.buffer + i) = 1;
        }
      } else {
        if (c == 0) {
          *(tape.buffer + i) = 1;
        } else {
          *(tape.buffer + i) = 0;
        }
      }
    }
  }
  // copy back the buffer into length
  for (let i: u64 = 0; i < length; i = i + 1) {
    *(tape.cells) = *(tape.buffer);
  }
}

fn main() {
  let tape: Tape;
  tape_new(&tape, 42);
  tape_update(&tape);
  tape_delete(&tape);
}

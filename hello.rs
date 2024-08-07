type u64 = integer<64, false>;
type char = integer<8, false>;

// from libc
fn malloc(size: u64) -> &void;
fn free(ptr: &void);
fn printf(fmt: &char, string: &char);

type Tape = struct {
  cells: &bool,
  buffer: &bool,
  repr: &char,
  length: u64
};

fn tape_new(tape: &Tape, length: u64) {
  tape.length = length;
  tape.cells = malloc(tape.length * sizeof(bool));
  tape.buffer = malloc(tape.length * sizeof(bool));
  tape.repr = malloc((tape.length + 1) * sizeof(char));
}

fn tape_delete(tape: &Tape) {
  if (tape.cells != nullptr) {
    free(tape.cells);
    tape.cells = nullptr;
  }
  if (tape.buffer != nullptr) {
    free(tape.buffer);
    tape.buffer = nullptr;
  }
  if (tape.repr != nullptr) {
    free(tape.repr);
    tape.repr = nullptr;
  }
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
    *(tape.cells + i) = *(tape.buffer + i);
  }
}

fn tape_print(tape: &Tape) {
  for (let i: u64 = 0; i < length; i = i + 1) {
    if (*(tape.cells + i)) {
      *(tape.repr + tape.length) = '1';
    } else {
      *(tape.repr + tape.length) = '0';
    }
  }
  *(tape.repr + tape.length) = '\0';
  printf("%s", tape.repr);
}

fn main() {
  let tape: Tape;
  tape_new(&tape, 20);
  tape_update(&tape);
  tape_print(&tape);
  tape_delete(&tape);
}

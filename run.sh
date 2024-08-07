#!/bin/bash
set -e

tree-sitter generate
tree-sitter build
tree-sitter parse hello.rf

project('tree-sitter-lart', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

tree_sitter_lart = library('tree-sitter-lart', [
  'src/parser.c',
])

tree_sitter_lart_dep = declare_dependency(
  #include_directories : 'src/tree_sitter',
  link_with : tree_sitter_lart
)

package tree_sitter_lart_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_lart "github.com/tree-sitter/tree-sitter-lart/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_lart.Language())
	if language == nil {
		t.Errorf("Error loading Lart grammar")
	}
}

package tree_sitter_lart_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-lart"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_lart.Language())
	if language == nil {
		t.Errolart("Error loading Lart grammar")
	}
}

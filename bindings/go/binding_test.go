package tree_sitter_rf_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-rf"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_rf.Language())
	if language == nil {
		t.Errorf("Error loading Rf grammar")
	}
}

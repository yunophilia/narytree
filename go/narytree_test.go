package narytree_test

import (
	narytree "narytree"
	"slices"
	"testing"
)

/*
 * 0
 * |- 1
 *    |- 2
 *    |- 3
 * |- 4
 *    |- 5
 */
func TestHandler(t *testing.T) {
	type Employee struct {
		Id   int
		Role string
	}
	root := narytree.New(&Employee{0, "CEO"}, 2)
	cto := narytree.New(&Employee{1, "CTO"}, 10)
	cto.AddChild(narytree.New(&Employee{2, "R&D Manager"}, 10))
	cto.AddChild(narytree.New(&Employee{3, "MIS Manager"}, 10))
	root.AddChild(cto)
	cfo := narytree.New(&Employee{4, "CFO"}, 10)
	cfo.AddChild(narytree.New(&Employee{5, "Sales Manager"}, 10))
	root.AddChild(cfo)

	list := make([]Employee, 0, 5)
	root.Traverse(func(data *Employee) (_ bool) {
		list = append(list, *data)
		return
	})

	expected := []Employee{
		{0, "CEO"},
		{1, "CTO"},
		{2, "R&D Manager"},
		{3, "MIS Manager"},
		{4, "CFO"},
		{5, "Sales Manager"},
	}

	if !slices.Equal(list, expected) {
		t.Error("Error")
	}
}

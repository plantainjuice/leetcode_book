package main

import (
	"fmt"
)

type WordDictionary struct {
	isWord bool
	children map[rune]*WordDictionary
}


/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{isWord: false, children: make(map[rune]*WordDictionary)}
}


func (this *WordDictionary) AddWord(word string)  {
	parent := this

	for _, ch := range word{
		if child, ok := parent.children[ch]; ok{
			parent = child
		}else{
			newChild := &WordDictionary{isWord: false, children: make(map[rune]*WordDictionary)}
			parent.children[ch] = newChild
			parent = newChild
		}
	}
    
	parent.isWord = true
}


func (this *WordDictionary) Search(word string) bool {
	parent := this

	for i, ch := range word{
		if ch == '.'{
			for _, child := range parent.children {
				if child.Search(word[i+1:]){
					return true
				}
			}
		}
		
		if child, ok := parent.children[ch]; ok{
			parent = child
			continue
		}

		return false
	}

	return parent.isWord
}

func main() {
	word := "apple"
	prefix := "app.."

	obj := Constructor();
	obj.AddWord(word);
	param_2 := obj.Search(prefix);

	fmt.Println(obj, param_2)
}

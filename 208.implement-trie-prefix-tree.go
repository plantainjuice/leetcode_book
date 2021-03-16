/*
 * @lc app=leetcode id=208 lang=golang
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
type Trie struct {
	isWord bool
	children map[rune]*Trie
}


/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{isWord: false, children: make(map[rune]*Trie)}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	parent := this

	for _, ch := range word{
		if child, ok := parent.children[ch]; ok{
			parent = child
		}else{
			newChild := &Trie{isWord: false, children: make(map[rune]*Trie)}
			parent.children[ch] = newChild
			parent = newChild
		}
	}
    
	parent.isWord = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	parent := this

	for _, ch := range word{
		if child, ok := parent.children[ch]; ok{
			parent = child
		}else{
			return false
		}
	}

	return parent.isWord
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	parent := this

	for _, ch := range prefix{
		if child, ok := parent.children[ch]; ok{
			parent = child
		}else{
			return false
		}
	}

	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end


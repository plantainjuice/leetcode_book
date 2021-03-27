/*
 * @lc app=leetcode id=901 lang=golang
 *
 * [901] Online Stock Span
 */

// @lc code=start
type Node struct {
    Val int
    res int
}

type StockSpanner struct {
    Spans []Node
}


func Constructor() StockSpanner {
    return StockSpanner{make([]Node, 0)}
}


func (this *StockSpanner) Next(price int) int {
    res := 1

    if len(this.Spans) == 0{
        this.Spans = append(this.Spans, Node{price, res})
        return res
    }

    for len(this.Spans) > 0 && this.Spans[len(this.Spans)-1].Val <= price{
        res += this.Spans[len(this.Spans) - 1].res
        this.Spans = this.Spans[:len(this.Spans) - 1]
    }

    this.Spans = append(this.Spans, Node{price, res})

    return res
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
// @lc code=end

# LRU-K
It's a page replacement algorithm.<br />
This method introduces a new approach to database disk buffering,called the LRU-K method.<br/> 
The basic idea of LRU-K is to keep track of the times of the last K references
to popular database pages, using this information to statistieally 
estimate the interarrival times of references on a page
by page basis. Although the LRU-K approach performs
optimal statistical inference under relatively standard assmuptions,
it is fairly simple and incurs little bookkeeping
overhead. As we demonstrate with simulation experiments,
the LRU-K algorithm surpasses conventional buffering algorithms
in discriminating between frequently and infrequently
referenced pages. In fact, LRU-K an approach the
behavior of buffering algorithms in which page sets with
known access frequencies are manually assigned to different
buffer pools of specifically tuned sizes. Unlike such customized
buffering algorithms however, the LRU-K method
is self-tuning, and does not rely on external hints about
workload characteristics. 
Furthermore, the LRU-K algorithm adapts in real time to changing patterns of access.




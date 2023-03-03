const bfs = () => {
  const queue = [];
  queue.push(1);
  while (queue.length) {
    const node = queue.shift();
    console.log(node);
    if (node * 2 <= 10) queue.push(node * 2);
    if (node * 2 + 1 <= 10) queue.push(node * 2 + 1);
  }
};

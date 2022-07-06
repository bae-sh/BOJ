const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, S, M] = input[0].split(' ').map(Number);
const arr = input[1].split(' ').map(Number);
let ans = -1;
const visit = Array.from({ length: N + 1 }, () => new Array(M + 1).fill(false));

function dfs(vol, idx) {
  visit[idx][vol] = true;

  if (idx === N) {
    ans = Math.max(ans, vol);
    return;
  }
  if (vol + arr[idx] <= M && !visit[idx + 1][vol + arr[idx]]) dfs(vol + arr[idx], idx + 1);
  if (vol - arr[idx] >= 0 && !visit[idx + 1][vol - arr[idx]]) dfs(vol - arr[idx], idx + 1);
}

dfs(S, 0);
console.log(ans);

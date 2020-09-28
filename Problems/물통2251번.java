import java.util.*;

class Pair2251 implements Comparable<Pair2251> {
    final int first;
    final int second;

    Pair2251(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
        public int compareTo(Pair2251 pair) {
            if (this.first < pair.first) {
                return -1;
            }
            if (this.first > pair.first) {
                return 1;
            }
            if (this.second < pair.second) {
                return -1;
            }
            if (this.second > pair.second) {
                return 1;
            }
            return 0;
        }

    public boolean equals(Object object) {
        if (object instanceof Pair2251) {
            Pair2251 pair = (Pair2251)object;
            return this.first == pair.first && this.second == pair.second;
        }
        return false;
    }

    public int hashCode() {
        int n = 3;
        n = 19 * n + this.first;
        n = 19 * n + this.second;
        return n;
    }
}
public class 물통2251번 {
    public static final int[] from = {0, 0, 1, 1, 2, 2};
    public static final int[] to = {1, 2, 0, 2, 0, 1};
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] cap = new int[3];
        for (int i=0; i<3; i++) {
            cap[i] = sc.nextInt();
        }
        int sum = cap[2];
        boolean[][] check = new boolean[201][201];
        boolean[] ans = new boolean[201];
        Queue<Pair2251> q = new LinkedList<Pair2251>();
        q.add(new Pair2251(0, 0));
        check[0][0] = true;
        ans[cap[2]] = true;
        while (!q.isEmpty()) {
            int[] cur = new int[3];
            Pair2251 p = q.peek();
            cur[0] = p.first;
            cur[1] = p.second;
            cur[2] = sum - cur[0] - cur[1];
            q.remove();
            for (int k=0; k<6; k++) {
                int[] next = {cur[0], cur[1], cur[2]};
                next[to[k]] += next[from[k]];
                next[from[k]] = 0;
                if (next[to[k]] >= cap[to[k]]) {
                    next[from[k]] = next[to[k]] - cap[to[k]];
                    next[to[k]] = cap[to[k]];
                }
                if (!check[next[0]][next[1]]) {
                    check[next[0]][next[1]] = true;
                    q.add(new Pair2251(next[0], next[1]));
                    if (next[0] == 0) {
                        ans[next[2]] = true;
                    }
                }
            }
        }
        for (int i=0; i<=cap[2]; i++) {
            if (ans[i]) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
import java.util.*;
import java.io.*;

public class 개미굴 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		TreeNode14725 root = new TreeNode14725(0);
		while (t-- > 0) {
			String s[] = br.readLine().split(" ");
			int n = Integer.parseInt(s[0]);
			TreeNode14725 curTree = root;
			for (int i = 1; i <= n; i++) {
				if (curTree.child == null) {
					TreeNode14725 tree = new TreeNode14725(s[1], curTree.dept + 1);
					curTree.insert(tree);
					curTree = tree;
				}else if (curTree.child.contains(s[i])) {
					int index = curTree.child.indexOf(s[i]);
					curTree = curTree.child.get(index);
				}

			}
		}
		print(root);
	}

	static void print(TreeNode14725 t) {
		Queue<TreeNode14725> q = new LinkedList();
		for (int i = 0; i < t.child.size(); i++) {
			q.add(t.child.get(i));
		}
		while (!q.isEmpty()) {
			TreeNode14725 test = q.poll();
			if (test.dept != 1) {
				for (int i = 0; i < test.dept; i++) {
					System.out.print("-");
				}
			}
			System.out.println(test.data);
			print(test);
		}
	}

}

class TreeNode14725 {
	ArrayList<TreeNode14725> child;
	String data;
	int dept;

	TreeNode14725(int dept) {
		this.dept = dept;
	}

	TreeNode14725(String data, int dept) {
		this.data = data;
		this.dept = dept;
		Collections.sort(child, new Comparator() {
			@Override
			public int compare(Object o1, Object o2) {
				TreeNode14725 t1 = (TreeNode14725) o1;
				TreeNode14725 t2 = (TreeNode14725) o2;
				if(t1.data==null||t2.data==null)
					return 0;
				return t1.data.compareTo(t2.data);
			}
		});
	}

	void insert(TreeNode14725 t) {
		child.add(t);
	}
}

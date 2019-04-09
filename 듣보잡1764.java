import java.util.*;
public class 듣보잡1764 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		HashSet<String> set1=new HashSet<>();
		LinkedList<String> list=new LinkedList<>();
		int n=sc.nextInt();
		int m=sc.nextInt();
		sc.nextLine();
		while(n-->0) {
			String s=sc.nextLine();
			set1.add(s);
		}
		while(m-->0) {
			String s=sc.nextLine();
			if(set1.contains(s)) {
				list.add(s);
			}
		}
		Collections.sort(list);
		System.out.println(list.size());
		for(int i=0;i<list.size();i++) {
			System.out.println(list.get(i));
		}
	}

}

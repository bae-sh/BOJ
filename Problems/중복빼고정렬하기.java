import java.util.*;
public class 중복빼고정렬하기 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Set<Integer> set= new HashSet();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			set.add(a);
		}
		int size=set.size();
		int p[]=new int[size];
		int cnt=0;
		Iterator<Integer> it=set.iterator();
		while(it.hasNext()) {
			p[cnt++]=it.next();
		}
		Arrays.sort(p);
		System.out.print(p[0]);
		for(int i=1;i<size;i++) {
			System.out.print(" "+p[i]);
		}
	}

}

package 백준;
import java.util.*;
public class 대표값2592번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Map<Integer,Integer> m=new HashMap();
		int avg=0;
		int max=0;
		int ans=0;
		for(int i=0;i<10;i++) {
			int a=sc.nextInt();
			avg+=a;
			if(m.get(a)==null)
				m.put(a, 1);
			else
				m.put(a,m.get(a)+1);
		}
		System.out.println(avg/10);
		for(Map.Entry<Integer, Integer> ma:m.entrySet()) {
			if(max<ma.getValue()) {
				ans=ma.getKey();
				max=ma.getValue();
			}
		}
		System.out.println(ans);
		
	}

}

import java.util.*;
public class 잃어버린괄호1541번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int ans=0;
		int cnt=0;
		boolean plus=true;
		String s=sc.nextLine();
		for(int i=0;i<s.length();i++) {
			char a=s.charAt(i);
			
			if(a=='+') {
				int k=Integer.parseInt(s.substring(cnt, i));
				if(plus) 
						ans+=k;
				else
					ans-=k;
				cnt=i+1;
			}
			else if(a=='-') {
				int k=Integer.parseInt(s.substring(cnt, i));
				if(plus) 
					ans+=k;
				else
					ans-=k;
				plus=false;
				cnt=i+1;
			}
			if(i==s.length()-1) {
				int k=Integer.parseInt(s.substring(cnt, i+1));
				if(plus)
					ans+=k;
				else
					ans-=k;
			}
		}
		System.out.println(ans);
	}

}

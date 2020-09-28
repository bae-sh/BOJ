import java.util.*;
public class 영화감독숌 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a[]=new String[10001];
		int num=sc.nextInt();
		int index=0;
		int n=666;
		while(true) {
			String temp=Integer.toString(n);
			if(num==index) {
				System.out.println(a[index]);
				System.exit(0);
			}
			n++;
			for(int i=0;i<temp.length()-2;i++) {
				if(temp.charAt(i)=='6'&&temp.charAt(i+1)=='6'&&temp.charAt(i+2)=='6') {
					a[++index]=temp;
					break;
				}
			}
		}
	}

}

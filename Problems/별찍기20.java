import java.util.*;
public class 별찍기20 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		String s="";
		for(int i=0;i<n*2;i++) {
			for(int j=0;j<n;j++) {
				s=(i+j)%2==0?"*":" ";
				sb.append(s);
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}

}

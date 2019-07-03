package 백준;
import java.util.*;
public class 회의실배정1931번 {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int start=0;
		int n=sc.nextInt();
		Meet m[]=new Meet[n];
		int cnt=0;
		for(int i=0;i<n;i++) {
			m[i]=new Meet();
			m[i]._start=sc.nextInt();
			m[i]._end=sc.nextInt();
		}
		Arrays.sort(m);
		for(int i=0;i<m.length;i++) {
			if(start<=m[i]._start) {
				cnt++;
				start=m[i]._end;
			}
		}
		System.out.println(cnt);
	}

}
class Meet implements Comparable{
	int _start;
	int _end;
	@Override
	public int compareTo(Object o) {
		Meet other=(Meet) o;
		if(_end>other._end) {
			return 1;
		}else if(_end<other._end)
			return -1;
		else {
			if(_start>other._start)
				return 1;
			if(_start<other._start)
				return -1;
			else
				return 0;
		}
	}
}
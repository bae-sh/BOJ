import java.util.*;
public class CPU {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			StringBuilder sb=new StringBuilder();
			boolean four=false;
			String s=sc.next();
			if(s.equals("ADD")) {
				sb.append("00000");
				four=true;
			}else if(s.equals("ADDC")) {
				sb.append("00001");
			}else if(s.equals("SUB")) {
				sb.append("00010");
				four=true;
			}else if(s.equals("SUBC")) {
				sb.append("00011");
			}else if(s.equals("MOV")) {
				sb.append("00100");
				four=true;
			}else if(s.equals("MOVC")) {
				sb.append("00101");
			}else if(s.equals("AND")) {
				sb.append("00110");
				four=true;
			}else if(s.equals("ANDC")) {
				sb.append("00111");
			}else if(s.equals("OR")) {
				sb.append("01000");
				four=true;
				four=true;
			}else if(s.equals("ORC")) {
				sb.append("01001");
			}else if(s.equals("NOT")) {
				sb.append("01010");
				four=true;
			}else if(s.equals("MULT")) {
				sb.append("01100");
				four=true;
			}else if(s.equals("MULTC")) {
				sb.append("01101");
			}else if(s.equals("LSFTL")) {
				sb.append("01110");
				four=true;
			}else if(s.equals("LSFTLC")) {
				sb.append("01111");
			}else if(s.equals("LSFTR")) {
				sb.append("10000");
				four=true;
			}else if(s.equals("LSFTRC")) {
				sb.append("10001");
			}else if(s.equals("ASFTR")) {
				sb.append("10010");
				four=true;
			}else if(s.equals("ASFTRC")) {
				sb.append("10011");
			}else if(s.equals("RL")) {
				sb.append("10100");
				four=true;
			}else if(s.equals("RLC")) {
				sb.append("10101");
			}else if(s.equals("RR")) {
				sb.append("10110");
				four=true;
			}else if(s.equals("RRC")) {
				sb.append("10111");
			}
			sb.append(0);
			int r=sc.nextInt();
			r=Integer.parseInt(Integer.toBinaryString(r));
			sb.append(String.format("%03d", r));
			r=sc.nextInt();
			r=Integer.parseInt(Integer.toBinaryString(r));
			sb.append(String.format("%03d", r));
			if(four==true) {
				r=sc.nextInt();
				r=Integer.parseInt(Integer.toBinaryString(r));
				sb.append(String.format("%03d", r));
				sb.append(0);
			}else {
				r=sc.nextInt();
				r=Integer.parseInt(Integer.toBinaryString(r));
				sb.append(String.format("%04d", r));
			}
			System.out.println(sb.toString());
		}
	}

}

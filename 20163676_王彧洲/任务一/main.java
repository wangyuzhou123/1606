package WuYang;
import java.util.*;
public class lianxi07 
{
public static void main(String[] args) 
  {
   int abcCount = 0;//Ӣ����ĸ����
   int spaceCount = 0;//�ո������
   int numCount = 0;//���ָ���
   int otherCount = 0;//�����ַ�����
   Scanner scan = new Scanner(System.in);//ɨ�������ܿ���̨��������Ϣ
   System.out.println("����һ���ַ�");
   String str = scan.nextLine();//ȡ������̨��һ����Ϣ,Ҳ�������������Ϣ
   char[] ch = str.toCharArray();//��ȡ�����ַ������һ��char����
   for (int i = 0; i<ch.length; i++)
       {
	if (Character.isLetter(ch[i])){
	//�ж��Ƿ���ĸ
	abcCount++;
		}
	else if (Character.isDigit(ch[i])){
	//�ж��Ƿ�����
	numCount++;
		}
	else if (Character.isSpaceChar(ch[i])){
	//�ж��Ƿ�ո��
	spaceCount++;
		}
	else{
	//���϶���������Ϊ�������ַ�
	otherCount++;
		}
	}
        System.out.println("��ĸ������" + abcCount);
	System.out.println("���ָ�����" + numCount);
	System.out.println("�ո������" + spaceCount);
	System.out.println("�����ַ�������" + otherCount);
  }
}
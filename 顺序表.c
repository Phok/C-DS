#include <stdio.h>
#include <stdlib.h>

#define Size 4

typedef struct Table{  
	int *head; //������һ��Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�ж�̬���� 
	int length; //��¼�˵�ǰ˳��ĳ��� 
	int size; //��¼��˳��������ڴ����� ���磬���ڳ��Ⱦ���4 
}table;

table initTable(){ // ˳���ĳ�ʼ�� 
	table t;  //����ǰ�涨��Ľṹ��������һ���ṹ����� 
	t.head=(int*)malloc(Size*sizeof(int));// ����һ���յ�˳�����̬����ռ� 
	// ��ʱ��head ָ����һ�������Լ�������ڴ�ռ�
	 
	if(!t.head){// �������ʧ�ܣ���Ϊ��ʾ�˳����� 
		printf ("��ʼ��˳���ʧ�ܣ�");
		exit(0);
	};
	t.length = 0;//�ձ�ĳ���Ϊ��
	t.size = Size; //�ձ�ĳ�ʼ���ռ�ΪSize
	return t; //�������õ�˳����أ����ص���һ����ʼ���õ����� 
} 


// ���뺯����tΪҪ��ӵ�˳���elemΪҪ�����Ԫ�أ�addΪ���뵽��λ�� 
table addTable(table t,int elem,int add){
	//�жϲ��뱾ʡ�Ƿ�������⣬���������Ԫ��λ�ñ����ű�ĳ���+1����
   //�����ȣ���β����������߲����λ�ñ��������ڡ������˳�
	if (add>t.length+1||add<1){
		printf("����λ��������");
		return t; 
	} 
	//���������ʱ������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ䣬��Ԫ�ز��룬���û�У�
	//��Ҫ����ռ�
	if (t.length==t.size){ //��ǰ���Ⱥ��������ʱ��˳���������Ҫ�ӿռ� 
		t.head=(int*)realloc(t.head,(t.size+1)*sizeof(int));//���·���ռ� 
		if(!t.head){
			printf("�洢����ʧ�ܡ�");
			return t;
		};
		
		t.size+=1;// �ɹ�֮��˳����������1��������Զ���䲻���ڴ��� 	
	};
	
	//�����������Ҫ���Ӳ����λ�ÿ�ʼ�ĺ���Ԫ�أ��������
	int i;
	for (i=t.length-1;i>add-1;i--){
		t.head[i+1]=t.head[i];
		
	}; 
	//������ɺ�ֱ�ӽ��������Ԫ�أ���ӵ�˳������Ӧλ�á�
	t.head[add-1]=elem;
	t.length+=1;//���������Ԫ�أ����Գ���Ҫ+1
	return t; 
} 

table delTable(table t,int del){
//������ɾ��Ԫ��ʱ��ֻ�轫��Ԫ������λ�ú����������Ԫ������ǰ�� 1 ��λ�ü���
	if (del>t.length||del<1){
		printf("ɾ��Ԫ���д���");
		exit(0);
	};
	//ɾ������
	int i;
	for (i=del;i<t.length;i++){
		t.head[i-1]=t.head[i];
		
	};
	t.length--;
	return t; 
}
int findTable(table t,int elem){//���Һ��������У�elem��ʾҪ���ҵ�����Ԫ�ص�ֵ
	int i;
	for (i=0;i<t.length;i++){
		if (t.head[i]==elem){
			return i+1;
		}
	}
	return -1;//����ʧ�ܷ���-1 
	
}


//���ĺ��������У�elemΪҪ���ĵ�Ԫ�أ�newElemΪ�µ�����Ԫ��
table changeTable(table t,int elem,int newElem){
	int add=findTable(t,elem);//���ò��Һ������ҵ�Ҫ�޸�Ԫ�ص�λ�� 
	t.head[add-1]=newElem;
	return t;
}

void displayTbale(table t){
	int i;
	for (i=0;i<t.length;i--){
		printf("%d,",t.head[i]);
	}
	printf ("\n");
}

int main(){
	table t1 =initTable();
	int i;
	for (i=1; i<=4; i++) {
        t1.head[i-1]=i;
        t1.length++;
    }
    displayTbale(t1);
}
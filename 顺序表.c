#include <stdio.h>
#include <stdlib.h>

#define Size 4

typedef struct Table{  
	int *head; //声明了一名为head的长度不确定的数组，也叫动态数组 
	int length; //记录了当前顺序的长度 
	int size; //记录了顺序表分配的内存容量 比如，现在长度就是4 
}table;

table initTable(){ // 顺序表的初始化 
	table t;  //利用前面定义的结构体来创建一个结构体变量 
	t.head=(int*)malloc(Size*sizeof(int));// 构造一个空的顺序表，动态申请空间 
	// 此时，head 指向了一块我们自己申请的内存空间
	 
	if(!t.head){// 如果申请失败，作为提示退出程序 
		printf ("初始化顺序表失败！");
		exit(0);
	};
	t.length = 0;//空表的长度为零
	t.size = Size; //空表的初始化空间为Size
	return t; //将创建好的顺序表返回，返回的是一个初始化好的链表 
} 


// 插入函数，t为要添加的顺序表，elem为要插入的元素，add为插入到的位置 
table addTable(table t,int elem,int add){
	//判断插入本省是否存在问题，（如果插入元素位置比整张表的长度+1还大）
   //如果相等，是尾随情况。或者插入的位置本生不存在。程序退出
	if (add>t.length+1||add<1){
		printf("插入位置有问题");
		return t; 
	} 
	//做插入操作时候，首先要看顺序表是否有多余的存储空间，给元素插入，如果没有，
	//需要申请空间
	if (t.length==t.size){ //当前长度和容量相等时候，顺序表满。需要加空间 
		t.head=(int*)realloc(t.head,(t.size+1)*sizeof(int));//重新分配空间 
		if(!t.head){
			printf("存储分配失败。");
			return t;
		};
		
		t.size+=1;// 成功之后将顺序表的容量加1，否则将永远分配不到内存了 	
	};
	
	//插入操作，需要将从插入的位置开始的后面元素，逐个后移
	int i;
	for (i=t.length-1;i>add-1;i--){
		t.head[i+1]=t.head[i];
		
	}; 
	//后移完成后，直接将所需插入元素，添加到顺序表的相应位置。
	t.head[add-1]=elem;
	t.length+=1;//由于添加了元素，所以长度要+1
	return t; 
} 

table delTable(table t,int del){
//数组中删除元素时，只需将该元素所在位置后的所有数据元素整体前移 1 个位置即可
	if (del>t.length||del<1){
		printf("删除元素有错误");
		exit(0);
	};
	//删除操作
	int i;
	for (i=del;i<t.length;i++){
		t.head[i-1]=t.head[i];
		
	};
	t.length--;
	return t; 
}
int findTable(table t,int elem){//查找函数，其中，elem表示要查找的数据元素的值
	int i;
	for (i=0;i<t.length;i++){
		if (t.head[i]==elem){
			return i+1;
		}
	}
	return -1;//查找失败返回-1 
	
}


//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table changeTable(table t,int elem,int newElem){
	int add=findTable(t,elem);//利用查找函数来找到要修改元素的位置 
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
#include<stdio.h>
#include<stdlib.h>//malloc的头文件 
#define FILENAME "stuinfor.txt" 
typedef struct stuinfor{
	int id;//结点数据 
	char name[10];//姓名
	char sex;//性别 
	float score;//成绩 
	struct stuinfor *next;//指向下一结点的指针 
}student;

student *head=NULL, *end=NULL;//头，尾指针

void menu()
{
     	printf("1.成绩录入(尾插法)\n");
     	printf("2.成绩录入(头插法)\n");
     	printf("3.成绩排序(按学号从小到大生成链表)\n");
	    printf("4.成绩修改\n");
	    printf("5.成绩删除\n");
	    printf("6.成绩查找\n");
	    printf("7.成绩显示\n");
	    printf("8.成绩保存\n");
	    printf("0.退出\n"); 
	    printf("----------\n");
	    printf("请输入菜单编号\n");
}

//录入（尾插法） 
void add1()
{
	student *p=(student *)malloc(sizeof(student));//动态分配内存空间
	printf("请输入学号：");
	scanf("%d",&p->id);
	printf("请输入姓名：");
	scanf("%s",p->name); 
	fflush(stdin);//清空前面的缓存 
	printf("请输入性别：（男/M,女/W）");
	scanf("%c",&p->sex);
	printf("请输入成绩：");
	scanf("%f",&p->score);
	//如果head为空，则当前结点是头结点也是尾结点
	if(head==NULL)
	{
		head=p;//当前结点的地址p赋给head,即head指向p，当前结点是头结点 
		end=p;//当前结点又是尾结点 
		p->next=NULL;//当前结点存放的地址为空 
		return;
    }
	//第二次开始时，end为上一个结点，p为当前新结点，即将上一个结点链接到当前新结点 
	end->next=p;
	//当前新结点存放的地址设置为空，即没有下一结点 
	p->next=NULL;
	//将end指向当前新结点，即当前新结点为尾结点 
	end=p;
	show(); 
} 
 
//录入（头插法） 
void add11()
{
	student *p=(student *)malloc(sizeof(student));//动态分配内存空间
	printf("请输入学号：");
	scanf("%d",&p->id);
	printf("请输入姓名：");
	scanf("%s",p->name); 
	fflush(stdin);//清空前面的缓存 
	printf("请输入性别：（男/M,女/W）");
	scanf("%c",&p->sex);
	printf("请输入成绩：");
	scanf("%f",&p->score);
	//如果head为空，则当前结点是头结点也是尾结点
	if(head==NULL)
	{
		head=p;//当前结点的地址p赋给head,即head指向p，当前结点是头结点 
		end=p;//头插法时 ，尾结点永远是第一个结点，所以end指针无意义  
		p->next=NULL;//当前结点存放的地址为空 
		show();
		return;
    }
	p->next=head;//把老的head的地址赋给新结点的next，即新结点指向上一个head 
	head=p;//新结点为头指针 
	show();
 } 
 
//显示学生信息 
void show()
{
    student *p=head;
    while (p!=NULL)
	{
        printf("学号：%d\n", p->id);
        printf("姓名：%s\n", p->name);
        printf("性别：%c\n", p->sex);
        printf("成绩：%.f\n", p->score); 
        printf("——————\n");
        p=p->next;
    }
}

//查找学生信息
void search()
{
    int i;
    printf("请输入要查找的学生学号：");
    scanf("%d",&i);

    student *p = head;
    while (p!= NULL)
	{
        if (p->id==i)
		{
            printf("学号：%d\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("性别：%c\n", p->sex);
            printf("成绩：%.f\n", p->score);
            return;
        }
        p=p->next;
    }
    printf("未找到学号为 %d 的学生信息。\n",i);
}

//修改学生信息
void edit()
{
	int i;
	student *p=head;
	char choose;
	printf("请输入要修改的学号：");
	scanf("%d",&i);
	fflush(stdin);
	while(p!=NULL)
	{
		if(p->id==i)
		{
			printf("找到了，你是否要修改：\n");
			choose=getchar();
			if(choose=='Y' || choose=='y')
			{
				printf("请输入新的成绩：");
				scanf("%f",&p->score);
				printf("修改成功！\n");
				printf("%-4d%-5s%-2c%.1f\n",p->id,p->name,p->sex,p->score);
				return;				
			}		
		}
		p=p->next;//移动到下一个结点 
	}
	printf("未找到\n");
} 

//删除学生信息（代码一） 
void del1() {
    int i;
    printf("请输入要删除的学生学号：");
    scanf("%d", &i);

    if (head == NULL)
	{
        printf("链表为空，没有学生信息！\n");
        return;
    }
    student *p = head, *prev = NULL;
    while (p!= NULL)
	{
        if (p->id==i)
		{
            if (prev==NULL)
			{
                // 删除的是头节点
                head=p->next;
                if (p->next==NULL)
				{
                    end = NULL;
                }
            } 
			else
			{
                 //删除的是中间或尾节点
                prev->next=p->next;
                if (p->next==NULL)
				{
                    end=prev;
                }
            }
            free(p);
            printf("删除成功！\n");
            show();
			return;
        }
        prev=p;
        p=p->next;
        
    }
    printf("未找到学号为 %d 的学生信息。\n", i);
}

//删除学生信息(代码二)
void del2() {
    int i;
    student *p=head, *prev=NULL; 
    printf("请输入要删除的学生学号：");
    scanf("%d", &i);
    //如果头结点就是要删除的结点
	if(head->id==i)
	{
		head=head->next;//head指向下一结点
		free(p);//释放原来head的内存空间
		printf("删除成功！\n"); 
		return;
	}
	//循环终止条件：p为空（即未找到），并且获取的学号等于输入的学号
	while(p!=NULL && p->id!=i)
	{
		prev=p;//指针盘移动前，将其地址赋给prev
		p=p->next;//移动到下一结点 
	} 
	//循环终止时，如果p不为空，则p为待删除节点
	if(p!=NULL)
	{
		prev->next=p->next;//将待删除的上一节点，指向待删除的下一结点
		free(p);
		printf("删除成功！\n"); 
	}
	//否则，找不到删除的结点
	else{
		printf("未找到学号为 %d 的学生信息。\n", i); 
	}
	show(); 
}

//学号排序 
void add_sort()
{
	student *p=(student *)malloc(sizeof(student));//动态分配内存空间
	student *p1=head,*prev=NULL; // 初始化两个指针 p1 和 prev，其中 p1 指向链表的头节点，prev 初始为 NULL
	printf("请输入学号：");
	scanf("%d",&p->id);
	printf("请输入姓名：");
	scanf("%s",p->name); 
	fflush(stdin);//清空前面的缓存 
	printf("请输入性别：（男/M,女/W）");
	scanf(" %c",&p->sex);
	printf("请输入成绩：");
	scanf("%f",&p->score);
	//head为空，或者新结点的学号小于老head的学号
	if(head==NULL || p->id<head->id)
	{
		p->next=head;//新结点指向老head
		head=p;//新结点为头结点
		return; 
	}
	//第二个结点开始，循环条件：p1不为空且新结点的学号大于老结点
	else{
		while(p1!=NULL && p->id>p1->id)
	{
		prev=p1;//每次移动前，将当前结点的地址赋给prev
		p1=p1->next;//移动到下一结点 
	} 
		}
	
	//循环终止时，prev为待插入位置上一节点，p1为下一结点
	prev->next=p;//将待插入节点的上一个结点，指向待插入节点（新结点） 
	p->next=p1;// 新结点指向下一个结点 
	show();
} 

void save()
{
	FILE *fp;
	student *p=head;
	//参数a+，可读，可写，可追加，如果文件不存在则创建
	if((fp=fopen(FILENAME,"a+"))==NULL)
	{
		printf("文件打开失败！\n");
		return;
	}
	while(p!=NULL)
	{
		fprintf(fp,"%-4d%-5s%-2c%.1f\n",p->id,p->name,p->sex,p->score);
		p=p->next;
	}
	fclose(fp);//关闭文件
	printf("文件保存成功！\n");
	return; 
}

int main()
{
    while(1)
	{
	    int m; 
	    menu();
		scanf("%d",&m);
		printf("你输入的是：%d\n",m);
		switch(m)
	{
		case 1:
		    add1();
		    break;
		case 2:
		    add11();
			break; 
		case 3:
			add_sort();
			break; 
		case 4:
		    edit();
			break;
		case 5:
		    //del1();
		    del2();
			break;
		case 6:
		    search();
			break;
		case 7:
		    //sort1();
		    //sort2();
		    show();
		    break;
		case 8:
			save();
			break;
		case 0:
		    printf("您已退出！\n");
		    //exit(0);
		default:
		    printf("输入错误！\n"); 
		 
	}
	}
	
	return 0;
}

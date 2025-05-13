#include<stdio.h>
#include<stdlib.h>//malloc��ͷ�ļ� 
#define FILENAME "stuinfor.txt" 
typedef struct stuinfor{
	int id;//������� 
	char name[10];//����
	char sex;//�Ա� 
	float score;//�ɼ� 
	struct stuinfor *next;//ָ����һ����ָ�� 
}student;

student *head=NULL, *end=NULL;//ͷ��βָ��

void menu()
{
     	printf("1.�ɼ�¼��(β�巨)\n");
     	printf("2.�ɼ�¼��(ͷ�巨)\n");
     	printf("3.�ɼ�����(��ѧ�Ŵ�С������������)\n");
	    printf("4.�ɼ��޸�\n");
	    printf("5.�ɼ�ɾ��\n");
	    printf("6.�ɼ�����\n");
	    printf("7.�ɼ���ʾ\n");
	    printf("8.�ɼ�����\n");
	    printf("0.�˳�\n"); 
	    printf("----------\n");
	    printf("������˵����\n");
}

//¼�루β�巨�� 
void add1()
{
	student *p=(student *)malloc(sizeof(student));//��̬�����ڴ�ռ�
	printf("������ѧ�ţ�");
	scanf("%d",&p->id);
	printf("������������");
	scanf("%s",p->name); 
	fflush(stdin);//���ǰ��Ļ��� 
	printf("�������Ա𣺣���/M,Ů/W��");
	scanf("%c",&p->sex);
	printf("������ɼ���");
	scanf("%f",&p->score);
	//���headΪ�գ���ǰ�����ͷ���Ҳ��β���
	if(head==NULL)
	{
		head=p;//��ǰ���ĵ�ַp����head,��headָ��p����ǰ�����ͷ��� 
		end=p;//��ǰ�������β��� 
		p->next=NULL;//��ǰ����ŵĵ�ַΪ�� 
		return;
    }
	//�ڶ��ο�ʼʱ��endΪ��һ����㣬pΪ��ǰ�½�㣬������һ��������ӵ���ǰ�½�� 
	end->next=p;
	//��ǰ�½���ŵĵ�ַ����Ϊ�գ���û����һ��� 
	p->next=NULL;
	//��endָ��ǰ�½�㣬����ǰ�½��Ϊβ��� 
	end=p;
	show(); 
} 
 
//¼�루ͷ�巨�� 
void add11()
{
	student *p=(student *)malloc(sizeof(student));//��̬�����ڴ�ռ�
	printf("������ѧ�ţ�");
	scanf("%d",&p->id);
	printf("������������");
	scanf("%s",p->name); 
	fflush(stdin);//���ǰ��Ļ��� 
	printf("�������Ա𣺣���/M,Ů/W��");
	scanf("%c",&p->sex);
	printf("������ɼ���");
	scanf("%f",&p->score);
	//���headΪ�գ���ǰ�����ͷ���Ҳ��β���
	if(head==NULL)
	{
		head=p;//��ǰ���ĵ�ַp����head,��headָ��p����ǰ�����ͷ��� 
		end=p;//ͷ�巨ʱ ��β�����Զ�ǵ�һ����㣬����endָ��������  
		p->next=NULL;//��ǰ����ŵĵ�ַΪ�� 
		show();
		return;
    }
	p->next=head;//���ϵ�head�ĵ�ַ�����½���next�����½��ָ����һ��head 
	head=p;//�½��Ϊͷָ�� 
	show();
 } 
 
//��ʾѧ����Ϣ 
void show()
{
    student *p=head;
    while (p!=NULL)
	{
        printf("ѧ�ţ�%d\n", p->id);
        printf("������%s\n", p->name);
        printf("�Ա�%c\n", p->sex);
        printf("�ɼ���%.f\n", p->score); 
        printf("������������\n");
        p=p->next;
    }
}

//����ѧ����Ϣ
void search()
{
    int i;
    printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
    scanf("%d",&i);

    student *p = head;
    while (p!= NULL)
	{
        if (p->id==i)
		{
            printf("ѧ�ţ�%d\n", p->id);
            printf("������%s\n", p->name);
            printf("�Ա�%c\n", p->sex);
            printf("�ɼ���%.f\n", p->score);
            return;
        }
        p=p->next;
    }
    printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����Ϣ��\n",i);
}

//�޸�ѧ����Ϣ
void edit()
{
	int i;
	student *p=head;
	char choose;
	printf("������Ҫ�޸ĵ�ѧ�ţ�");
	scanf("%d",&i);
	fflush(stdin);
	while(p!=NULL)
	{
		if(p->id==i)
		{
			printf("�ҵ��ˣ����Ƿ�Ҫ�޸ģ�\n");
			choose=getchar();
			if(choose=='Y' || choose=='y')
			{
				printf("�������µĳɼ���");
				scanf("%f",&p->score);
				printf("�޸ĳɹ���\n");
				printf("%-4d%-5s%-2c%.1f\n",p->id,p->name,p->sex,p->score);
				return;				
			}		
		}
		p=p->next;//�ƶ�����һ����� 
	}
	printf("δ�ҵ�\n");
} 

//ɾ��ѧ����Ϣ������һ�� 
void del1() {
    int i;
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%d", &i);

    if (head == NULL)
	{
        printf("����Ϊ�գ�û��ѧ����Ϣ��\n");
        return;
    }
    student *p = head, *prev = NULL;
    while (p!= NULL)
	{
        if (p->id==i)
		{
            if (prev==NULL)
			{
                // ɾ������ͷ�ڵ�
                head=p->next;
                if (p->next==NULL)
				{
                    end = NULL;
                }
            } 
			else
			{
                 //ɾ�������м��β�ڵ�
                prev->next=p->next;
                if (p->next==NULL)
				{
                    end=prev;
                }
            }
            free(p);
            printf("ɾ���ɹ���\n");
            show();
			return;
        }
        prev=p;
        p=p->next;
        
    }
    printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����Ϣ��\n", i);
}

//ɾ��ѧ����Ϣ(�����)
void del2() {
    int i;
    student *p=head, *prev=NULL; 
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%d", &i);
    //���ͷ������Ҫɾ���Ľ��
	if(head->id==i)
	{
		head=head->next;//headָ����һ���
		free(p);//�ͷ�ԭ��head���ڴ�ռ�
		printf("ɾ���ɹ���\n"); 
		return;
	}
	//ѭ����ֹ������pΪ�գ���δ�ҵ��������һ�ȡ��ѧ�ŵ��������ѧ��
	while(p!=NULL && p->id!=i)
	{
		prev=p;//ָ�����ƶ�ǰ�������ַ����prev
		p=p->next;//�ƶ�����һ��� 
	} 
	//ѭ����ֹʱ�����p��Ϊ�գ���pΪ��ɾ���ڵ�
	if(p!=NULL)
	{
		prev->next=p->next;//����ɾ������һ�ڵ㣬ָ���ɾ������һ���
		free(p);
		printf("ɾ���ɹ���\n"); 
	}
	//�����Ҳ���ɾ���Ľ��
	else{
		printf("δ�ҵ�ѧ��Ϊ %d ��ѧ����Ϣ��\n", i); 
	}
	show(); 
}

//ѧ������ 
void add_sort()
{
	student *p=(student *)malloc(sizeof(student));//��̬�����ڴ�ռ�
	student *p1=head,*prev=NULL; // ��ʼ������ָ�� p1 �� prev������ p1 ָ�������ͷ�ڵ㣬prev ��ʼΪ NULL
	printf("������ѧ�ţ�");
	scanf("%d",&p->id);
	printf("������������");
	scanf("%s",p->name); 
	fflush(stdin);//���ǰ��Ļ��� 
	printf("�������Ա𣺣���/M,Ů/W��");
	scanf(" %c",&p->sex);
	printf("������ɼ���");
	scanf("%f",&p->score);
	//headΪ�գ������½���ѧ��С����head��ѧ��
	if(head==NULL || p->id<head->id)
	{
		p->next=head;//�½��ָ����head
		head=p;//�½��Ϊͷ���
		return; 
	}
	//�ڶ�����㿪ʼ��ѭ��������p1��Ϊ�����½���ѧ�Ŵ����Ͻ��
	else{
		while(p1!=NULL && p->id>p1->id)
	{
		prev=p1;//ÿ���ƶ�ǰ������ǰ���ĵ�ַ����prev
		p1=p1->next;//�ƶ�����һ��� 
	} 
		}
	
	//ѭ����ֹʱ��prevΪ������λ����һ�ڵ㣬p1Ϊ��һ���
	prev->next=p;//��������ڵ����һ����㣬ָ�������ڵ㣨�½�㣩 
	p->next=p1;// �½��ָ����һ����� 
	show();
} 

void save()
{
	FILE *fp;
	student *p=head;
	//����a+���ɶ�����д����׷�ӣ�����ļ��������򴴽�
	if((fp=fopen(FILENAME,"a+"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	while(p!=NULL)
	{
		fprintf(fp,"%-4d%-5s%-2c%.1f\n",p->id,p->name,p->sex,p->score);
		p=p->next;
	}
	fclose(fp);//�ر��ļ�
	printf("�ļ�����ɹ���\n");
	return; 
}

int main()
{
    while(1)
	{
	    int m; 
	    menu();
		scanf("%d",&m);
		printf("��������ǣ�%d\n",m);
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
		    printf("�����˳���\n");
		    //exit(0);
		default:
		    printf("�������\n"); 
		 
	}
	}
	
	return 0;
}

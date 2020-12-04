#include<stdio.h>
#include<conio.h>
#include<string.h>
struct tree
{
	struct tree *left;
	char word[128],meaning1[256],meaning2[255];
	struct tree *right;
};
typedef struct tree node;
void insert(char*,char*,char*);
void del(char*);
void search(char*);
void display(node*);
void pause();
node *root=NULL;

//creating a node//
node*create(char*word,char*meaning1,char*meaning2)
{
	node*new1;
	new1=(node*)malloc(sizeof(node));
	strcpy(new1->word,word);
	strcpy(new1->meaning1,meaning1);
	strcpy(new1->meaning2,meaning2);
	new1->left=new1->right=NULL;
	return new1;
}

//displaying data in inorder traversal//
void display(node*root)
{
	if(root)
	{
		display(root->left);
		printf("word\t:\t%s\n",root->word);
		printf("meaning\t:\t%s\n",root->meaning1);
		printf("meaning\t:\t%s\n\n",root->meaning2);
		display(root->right);
	}
}

//deleting node from requested position//
void del(char*str)
{
	node*parent=NULL,*cur=NULL,*temp=NULL;
	int flag=0,res=0;
	if(root==NULL)
	{
		printf("\n\tTRY INSERTING DATA RATHER THEN DELETING!!\n");
		return;
	}
	cur=root;
	while(1)
	{
		res=stricmp(cur->word,str);
		if(res==0)
		{
			printf("\n\nWORD FOUND READY TO GET DELETED#!#\n");
			printf("\nW_O_R_D D_E_L_E_T_E_D !!\n");
			break;
		}
			//traversing to the given word
			flag=res;
			parent=cur;
			if(res>0)
				cur=cur->left;
			else
				cur=cur->right;
			if(cur==NULL)
				return;
	}
	      //deleting the node with respect to its position//
		if(cur->right==NULL)
		{
			if(cur==root&&cur->left==NULL)
			{
				free(cur);
				root=NULL;
				return;
			}
			else if(cur==root)
			{
				root=cur->left;
				free(cur);
				return;
			}
			if(flag>0)
				parent->left=cur->left;
			else
				parent->right=cur->left;
		}
		else
		{
			temp=cur->right;
			if(temp->left==NULL)
			{
				temp->left=cur->left;
				if(temp->left==NULL)
				{
					temp->left=cur->left;
					if(cur==root)
					{
						root=temp;
						free(cur);
						return;
					}
					if(flag>0)
						parent->left=temp;
					else
						parent->right=temp;
				}
				else
				{
					node *successor=NULL;
					while(1)
					{
						successor=temp->left;
						if(successor->left==NULL)
							break;
						temp=successor;
					}
					temp->left=successor->right;
					successor->left=cur->left;
					successor->right=cur->right;
					if(cur==root)
					{
						root=successor;
						free(cur);
						return;
					}
					if(flag>0)
						parent->left=successor;
					else
						parent->right=successor;
				}
			}
			free(cur);
			return;
		}

}

//inserting node  //
void insert(char*word,char*meaning1,char*meaning2)
{
	node*parent=NULL,*cur=NULL,*new1=NULL;
	int res=0;
	if(root==NULL)
	{
		root=create(word,meaning1,meaning2);
		return;
	}
	for(cur=root;cur!=NULL;cur=(res>0)?cur->right:cur->left)
	{
		res=stricmp(word,cur->word);
		if(res==0)
		{
			printf("\n\tDUPLICATE ENTRY!!\n\tWORD EXIST!!!!\n");
			return;
		}
		parent=cur;
	}
	new1=create(word,meaning1,meaning2);
	if(res>0)
		parent->right=new1;
	else
		parent->left=new1;
	return;
}

//searching a word//
void search(char*str)
{
	node*temp=NULL;
	int flag=0,res=0;
	if(root==NULL)
	{
		printf("\n\tTHERE ARE NO WORDS!!\n\n");
		printf("E_M_P_T_Y D_I_C_T_I_O_N_A_R_Y\n");
		return;
	}
	temp=root;
	while(temp)
	{
		if((res=stricmp(temp->word,str))==0)
		{
			printf("word\t:\t%s\n",str);
			printf("meaning\t:\t%s\n",temp->meaning1);
			printf("meaning\t:\t%s\n",temp->meaning2);
			flag=1;
			break;
		}
		if(res>0)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(flag==0)
		printf("\tWORD NOT FOUND!!\n");
	return;
}
//for some break //
void pause()
{
	int a,i,j;
	for(i=0;i<20000;i++)
		for(j=0;j<2000;j++)
			a++;
}

void main()
{
	int ch;
	char c;
	char word[128],meaning1[256],meaning2[255];
	char str[120];
	clrscr();
	pause();
	printf("\t\t\tWELCOME TO WORD BANK OF YOUR OWN\n\t\t\t\t\tFOR\n\t\t\tRECOGNIZING SOMETHING NEW\n");
	pause();
	while(1)
	{
		printf("\n1.Insertion\t2.Deletion\n3.Searching\t4.Display\n5.Exit\n");
		printf("enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			clrscr();
			printf("\t\t\tWELCOME TO WORD BANK OF YOUR OWN\n\t\t\t\t\tFOR\n\t\t\tRECOGNIZING SOMETHING NEW\n");
			printf("\n\t<<<USING INSERT FUNCTION>>>\n");
			printf("word to insert:\t\n");
			scanf("%s",word);
			printf("\none word meaning:\n");
			scanf("%s",meaning1);
			printf("\none word meaning:\n");
			scanf("%s",meaning2);
			insert(word,meaning1,meaning2);
			pause();
			printf("\tW_O_R_D_I_N_S_E_R_T_E_D !!!\n");
			break;
			case 2:
			clrscr();
			printf("\t\t\tWELCOME TO WORD BANK OF YOUR OWN\n\t\t\t\t\tFOR\n\t\t\tRECOGNIZING SOMETHING NEW\n");
			printf("\n\t<<<USING DELETE FUNCTION>>>\n");
			printf("enter the word to delete:\n");
			scanf("%s",str);
			del(str);
			pause();
			break;
			case 3:
			clrscr();
			printf("\t\t\tWELCOME TO WORD BANK OF YOUR OWN\n\t\t\t\t\tFOR\n\t\t\tRECOGNIZING SOMETHING NEW\n");
			printf("\n\t<<<USING SEARCH FUNCTION>>>\n");
			printf("enter the search word:\n");
			scanf("%s",str);
			search(str);
			pause();
			printf("SEARCH AGAIN ANYTIME\n");
			break;
			case 4:
			clrscr();
			printf("\t\t\tWELCOME TO WORD BANK OF YOUR OWN\n\t\t\t\t\tFOR\n\t\t\tRECOGNIZING SOMETHING NEW\n");
			printf("\n\t<<<USING DISPLAY FUNCTION>>>\n");
			display(root);
			pause();
			printf("\t\tSEE YOU SOON *_*\n");
			break;
			case 5:
			printf("\nTHANKS FOR YOUR VISIT\n");
			printf("\tHOPE TO SEE YOU SOON:)\n");
			pause();
			pause();
			exit(0);
			default:
			printf("\nYou have entered wrong option\n");
			printf("try again!!\n");
			break;
		}
	}
	getch();
}

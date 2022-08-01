void busca_em_largura(grafo*g,int v)//usar uma fila fazer esse antes
{
	int cor[100];
	int d[100];
	int pi[100];	

	vertice *s;
	aresta *a;
		
	int i,des,auxd=0,conts=0;//contador da distancia

	lista *q = malloc(sizeof(q));
	
	inicializa_lista(q);
	
	for(s = g->inicio; s != NULL && s->nome != v ; s = s->proxvertice); //acho o vertice	
	
	for(i=0;i<100;i++)
	{
		cor[i]=0;
		d[i]=-1;
		pi[i]=-1;
	}	
	 
	cor[s->nome]=1;
	d[s->nome]=0;
	pi[s->nome]=-1;
	enfila(q,s->nome);
	
	while(s != NULL)
	{
		conts++;
		if(cor[s->nome] == 1)
		{	
			a=s->proxaresta;
			
			if(a != NULL) 
			{
				
				while(a!= NULL && cor[a->nome] == 2)
				{
					a=a->proximo;
				}
								
				if(a!= NULL && cor[a->nome] == 0)
				{
					
					while(a != NULL)
					{
						if(cor[a->nome] == 1)
						{
							cor[a->nome] = 2;
							a=a->proximo;	
						}
						
						else if(cor[a->nome] == 0)
						{
						
							cor[a->nome] = 1;
							pi[a->nome]=s->nome;
							d[a->nome]=d[pi[a->nome]] +1;
							enfila(q,a->nome);
							a=a->proximo;
						}	
						else
						{
							a=a->proximo;
						}						
					}
				}
				if(a!= NULL && cor[a->nome] == 1)
				{
					cor[a->nome] =1;
				}
				des = desenfila(q);
				cor[des] = 2;	
			}	
		}
		s= s->proxvertice;
	}

	s = g->inicio;
	int aux;
	while(s != NULL)
	{	
		if(pi[s->nome] == -1)
		{
			a=s->proxaresta;
			while(a!= NULL)
			{
				if(pi[a->nome] != -1)
				{
					aux=a->nome;		
					pi[s->nome] = aux;
					d[s->nome] = d[aux]+1;
				}
				a=a->proximo;
			}		
		}				
		
		s=s->proxvertice;	
	}
	s=g->inicio; 
	cor[v]=1;
	d[v]=0;
	pi[v]=-1;


	printf("vert   dist  pi\n");
	
	for(i=1;i<=g->quantidade;i++)
	{
		printf(" %d\t%d\t%d\n",i,pi[i],d[i]);
		
	}
	
	printf("\n");			 
	free(q);
}
int ver_se_vertice_exi(grafo *g,int num)   // função que retorna 1 se o vertice existe ou 0 se ele não existe
{
	vertice *ah;
	
	for(ah = g->inicio; ah != NULL; ah=ah->proxvertice)
	{
		if(ah->nome == num)
		{
			return 1; 
		}
	}
	return 0;
}

int quantidade_de_vertice(grafo *g)
{
	vertice *v;
	int cont=0;
	for(v=g->inicio; v!= NULL ; v = v->proxvertice)
	{
		cont++;
	}	
	return cont;
} 

int achar_peso(grafo *g,grafo *prim) // acha o menor peso que esta em prim em g
{
	vertice *v,*u;
	aresta *a;
	int menor=20000;
	v=prim->inicio;
	
	while(v!= NULL)
	{	
		u= achar_vertice_int(v->nome,g);
		a=u->proxaresta;
		while(a!= NULL)
		{
			if(a->peso < menor && ver_se_vertice_exi(prim,a->nome) == 0)
			{
				menor=a->peso;
			}
			a=a->proximo;
		}
		v=v->proxvertice;
	}
	return menor;
}

void prim(grafo *g,int a)
{
	grafo *prim = malloc(sizeof(grafo));
	inicializa_grafo(prim);
	int menor,var;
	aresta *aux;
	vertice *v,*vp,*p;
	var = quantidade_de_vertice(g);
	
	listad *ja = malloc(sizeof(listad));
	inicializa_listad(ja);
	
	v = achar_vertice_int(a,g);
	
	inserir_vertice(prim,a);
	v=g->inicio;
	vp=prim->inicio;
	empilhad(ja,v->nome,-1, 0);
	p=g->inicio;

	while(var != quantidade_de_vertice(prim)) 
	{           	
		aux=v->proxaresta;
		menor = achar_peso(g,prim);
		
		p=prim->inicio;
		
		while(p !=NULL)
		{	
			vertice *q = achar_vertice_int(p->nome,g);
			aresta *a;	
			a=q->proxaresta;
			
			menor = achar_peso(g,prim);
			while(a!=NULL && menor != 20000)
			{
				
				if(a->peso <= menor)
				{
										
					inserir_vertice(prim,a->nome);
					
					if(ver_se_existe_na_lista(ja,a->nome) == 1)
					{
						trocar(ja,q->nome,a->nome,a->peso);							
					}
					else
					{
						empilhad(ja,a->nome,q->nome, a->peso);
					}
				}
				
				a=a->proximo;
			}
			p=p->proxvertice;
		}
	}	
		
	print_pilhad(ja->inicio);
}
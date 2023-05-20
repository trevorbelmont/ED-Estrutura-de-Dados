cxx=g++
cflags=-w
# No encadeamento de comandos em uma regra a separação por ; ou  && tende a ser essencial
# Use ; para separar comandos com execuções independentes e && para encadear um comando que depende do sucesso do anterior
# Quebra de linha simples (sem ponto e vírgula) é entendida como &&

#.PHONE: nome_da_regra   (logo acima da definição da regra). 
# Faz com que a regra seja executada sempre que invocada, não checando ou considerando modificações de dependencias
# Também é útil para diferenciar regras que não possuem associação com arquivos - neste caso o makefile não procurará pelo arquivo.
# Especialmente útil quando temos arquivos com o mesmo nome de uma regra. No geral é pouco usado. 

# := ou = ? Atribuição simples ourecursiva e porque:

# O OPERADOR DE ATRIBUIÇÃO SIMPLES/ÚNICA, := ,tem espanção imediata (eager expansion), e é avaliado apenas na primeira ocorrência.
# Se por um lado a eager expansion pode ser mais eficiente em termos de desempenho, porém é sempre estática.

# o OPERADOR DE ATRIBUIÇÃO RECURSIVA, = , por outro lado possui expansão mais preguiçosa (lazy expansion) comparada com :=. 
# Isso por que o operador = avalia a variável apenas quando esta é usada porém sempre que ela é usada.
# Variáveis inicializadas e definidas com = podem ter seus valores modificados ao longo do makefile.

# APENDING ATTRIBUTION, += . Similar a um string concat ou o operador += em qualquer linguagem.

obj := obj
src := src
incld := include
lib := lib
bin := bin
tests := tests

programa = exe # Nome do executável programa 
target := ${bin}/${programa} # Endereço do executável do programa compilado

# ------------- WILDCARDS e SUBSTITUIÇÃO DE STRINGS E SUFIXOS ---------------------------------------------
# uma variável com wildcard É UMA LISTA DE ARQUIVOS que seguem o padrão estabelecido. Alguns comandos funcionam melhor com listas (wildcards).
# Wildcard é ligeiramente diferente de usar " *.sufixo ". Uma vez que o asterisco não é uma lista. E também é diferente de %.

# Susbstituição de sufixos	":"
# ex: NOVA_VARIAVEL := $(SRCS:.cpp=.o)   Aqui se está criando uma nova variável 
# ao qual se está atribuido toda lista de variáveis SRCS porem com o sufixo ".cpp" trocado por ".o"

# Substituição de string por padrão (pattern):		"patsubst"
# Sintaxe (patsubst old_%_pattern,new_%_pattern,${variável_fonte})    #não deve conter espaços - que são lidos como parte dos nomes.
# ex (declarando variável): all_objs = $(patsubst src/%.cpp,obj/%.o,$(all_srcs))	

sources = $(wildcard ${src}/*.cpp) 							#all_srcs REPRESENTA a lista de todos os .cpps na pasta src.
objetcts = $(patsubst ${src}/%.cpp,${obj}/%.o,$(sources))		#all_objs  a lista de todos os .o na pasta obj nomeados pelos .cpp.
headers = $(wildcard ${incld}/*.h*)		 					# Aglutina qualquer arquivo com extensão começando com .h* (.hpp ou .h) na pasta include
libraries= $(wildcard $(lib)/*)									# Uma lista com todos os arquivos na pasta lib

# Variáveis Notáveis:
#			$@  : refere o alvo da regra de compilação em questão (que vem antes dos dois pontos)
#			$^	: Lista que refere a todos os pré-requisitos da regra.
#			$?	:	lista que faz referência apenas aos pré-requisitos mais recentemente modificados que o alvo da regra.
#			$<	: Refere apenas ao primeiro pré-requisito da regra. Nota: não existe $>.

# Compila o executável com todos os pré-requisitos ($^) e nomeando com o nome da regra ($target) usando $@
${target}: $(objetcts) $(headers)
	${cxx} ${cflags} $^ -o $@ 

# Compila o objeto qualqeur objeto, %. Dependências: seu próprio cpp e TODAS os headers
${obj}/%.o:  ${src}/%.cpp $(headers)
	${cxx} ${cflags} -c -I ${incld} $< -o $@



run: ${target}
	./$(target)

# Apaga apenas os .o e executáveis previstos neste makefile

clean:
	rm ${target}; rm -r ${objetcts}


actual_objects = ${wildcard $(obj)/*.o}
list:
	printf "|--Sources \n|     |-- ${sources} \n|--Headers: \n|     |-- ${headers} \n|--Objects: \n|     |-- ${actual_objects} \n|--Libraries: \n|     |-- ${libraries} \n|--Executable (bin): \n|     |--${target}\n"
	
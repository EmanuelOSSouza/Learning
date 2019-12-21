/*
 * Número primo
 * Data: 17/09/2019
 * Autor: Emanuel Souza (https://github.com/EmanuelOSSouza/Learning)
 * Descrição: Verificar se o número digitado é primo ou não. O software de verificação
 * de número primos apesar de ser simples para codificar é considerado um problema de dificil 
 * resolução computacional. Isto devido a esta resolução pertencer ao grupo de problemas conhecidos
 * como NP - Tempo polinomial não determinístico - (Non-Deterministic Polynomial time, em inglês). Pois 
 * descobrir um número primo implica em fatorar este número por todos os números entre 1 até ele mesmo, caso
 * ele seja dividido apenas por 1 e por ele mesmo, o número inserido é primo. Portanto, quanto maior for o número 
 * mais dificil se torna o problema e mais tempo o computador gastará para chegar ao resultado.  
 * Notação assintotica de complexidade: O(log² n).
*/

num = int(input("Digite um número:"))
def numero_primo(num):
	count=1
	primo=0
	while count <= num:
		if (num%count)==0:
			print("O número %s é disvisivel por %s" %(num,count))
			primo=primo+1
		count=count+1
	if primo==2:
		print("O número %s é primo" %(num))
	else:
		print("O número %s não é primo" %(num))
	return count

numero_primo(num)
input()



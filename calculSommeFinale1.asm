.globl calculSommeFinale1

calculSommeFinale: 

	beq $t4, 1, type1 # typeMise == 1
	
	
	
	
	
	
	
	
	type1: 
		beq $t9, $t3, type1Et # numero_gagnant == numero_choisi pour 1
		j finCalculSommeFinale1
		type1Et: 

	








	finCalculSommeFinale1:

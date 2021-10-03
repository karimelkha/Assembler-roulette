.data 
	rmulti: 	.asciiz "Roulette Multiplayer\nOn va demarrer la partie\nVous commencez avec une somme de 2000$. Bonne chance!\n"
	cash1: 		.word 2000
	cash2: 		.word 2000
	mise1: 		.word 0
	mise2: 		.word 0
	numero_choisi1: .word 0
	numero_choisi2: .word 0
	type_mise1: 	.word 0
	type_mise2: 	.word 0
	numero_gagnant: .word 0
	reponse: 	.space 3
	reset:		.word 1
	couleur_gagnante:.word 1
	continuer:	.asciiz "Voulez-vous continuer a jouer? (oui = 1, non = 0)\n"
	ecrire_mise1: 	.asciiz "Joueur 1, merci d'ecrire votre mise.\n"
	ecrire_mise2 : 	.asciiz "Joueur 2, merci d'ecrire votre mise.\n"
	liste_mises: 	.asciiz "\nMerci d'indiquer votre type de mise, voici la liste:\n Plein : 1\n Cheval : 2\n Transversale : 3\n En carre : 4\n En sixain : 5\n Rouge : 6\n Noire : 7\n Pair : 8\n Impair : 9\n Manque : 10\n Passe : 11\n Douzaine :\n  DP : 12\n  DM : 13\n  DD : 14\n Douzaines a cheval : 15\n Colonne : 16\n Colonne a cheval : 17\n\n"
	ecrire_numero: 	.asciiz "Merci d'ecrire le numero choisi.\n" 





.text

	main: 
		# Printf Intro
		li $v0, 4
		la $a0, rmulti
		syscall
		
		while:
			# $t0 = reset
			lw $t0, reset
		
			# Printf + scanf mise1
			# $t1 = mise1
			li $v0, 4
			la $a0, ecrire_mise1
			syscall
			li $v0, 5
			syscall
			add $t1, $v0, $zero
			
			# $t2 = cash1 = cash1 - mise1
			lw $t2, cash1
			sub $t2, $t2, $t1
			
			# Printf + scanf numero_choisi1
			# $t3 = numero_choisi1
			li $v0, 4
			la $a0, ecrire_numero
			syscall
			li $v0, 5
			syscall
			add $t3, $v0, $zero
			
			# Printf liste type mise + scanf type_mise1
			# $t4 = type_mise1
			li $v0, 4
			la $a0, liste_mises
			syscall
			li $v0, 5
			syscall
			add $t4, $v0, $zero
			
			# Printf + scanf mise 2 
			# $t5 = mise2
			li $v0, 4
			la $a0, ecrire_mise2
			syscall
			li $v0, 5
			syscall
			add $t5, $v0, $zero
			
			# $t6 = cash2 = cash2 - mise2
			lw $t6, cash2
			sub $t6, $t6, $t5
			
			# Printf + scanf numero_choisi2
			# $t7 = numero_choisi2
			li $v0, 4
			la $a0, ecrire_numero
			syscall
			li $v0, 5
			syscall
			add $t7, $v0, $zero
			
			# Printf liste type mise + scanf type_mise2
			# $t8 = type_mise2
			li $v0, 4
			la $a0, liste_mises
			syscall
			li $v0, 5
			syscall
			add $t8, $v0, $zero
			
			# numero_gagnant = $t9 =  random entre 0 et 36
			li $a1, 36  # random <= 36
   		  	li $v0, 42  # appel système random
   		 	syscall
   		 	add $t9, $a0, $zero
   		 	
   		 	jal couleurGagnante
   		 	# couleur gagnante = $s0
   		 	
   		 	#jal calculSommeFinale1
   		 	
   		 	
   		 	
   		 	
   		 	
   		 	
    			
			

   	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
			
			
			
		
		
		
		
		
		
			# Printf question si continuer
			li $v0, 4
			la $a0, continuer
			syscall
			
			# Scanf reset
			li $v0, 5
			syscall
			add $t0, $v0, $zero
			
			# si reset = 0 sortir de la boucle 
			beqz $t0, finWhile
			
			j while
			
		
		finWhile:
		
		# Fin  programme
		addi $v0, $zero, 10
		syscall
		
	

.globl couleurGagnante

couleurGagnante: 	

	# si numero gagnant == 0 alors nouveau tour 
	beqz $t9, cas0
	
	# sinon si numero gagnant <= 10 ou ( >18 && <29)
	ble $t9, 10, moinsOuEgal10
	
	bgt $t9, 18, plusQue18
	
	j autreCas
	
	
	cas0: 
		# mise à jour valeur cash1 & cash2
		add $t2, $t2, $t1
		add $t6, $t6, $t5
		j finCouleurGagnante
		
	moinsOuEgal10: 
		# si numero gagnant %2 == 0 alors noir(1), sinon rouge(0)
		ori $a0, $a0, 0
		div $a0, $t9, 2
		mfhi $a0
		beqz $a0, moinsOuEgal10EtPair
		# impair et donc rouge(0)
		li $s0, 0
		
		j finCouleurGagnante
		
		
		moinsOuEgal10EtPair: 
			li $s0, 1
			
			j finCouleurGagnante
			
	plusQue18: 
		blt $t9, 29, plusQue18EtMoinsQue29
		j plusQue18MaisPasMoinsQue29
		
		plusQue18EtMoinsQue29: 
		 	# si numero gagnant %2 == 0 alors noir(1), sinon rouge(0)
			ori $a0, $a0, 0
			div $a0, $t9, 2
			mfhi $a0
			beqz $a0, etcEtPair
			# impair et donc rouge(0)
			li $s0, 0
			j finCouleurGagnante
			
			etcEtPair:
				li $s0, 1
				j finCouleurGagnante 
				
		plusQue18MaisPasMoinsQue29:
			j autreCas
		
	autreCas: 
	
	# si numero gagnant %2 == 0 alors rouge(0), sinon noir(1) (autre cas)
	ori $a0, $a0, 0
	div $a0, $t9, 2
	mfhi $a0
	beqz $a0, autreCasEtPair
	# impair et donc noir(1)
	li $s0, 1
	j finCouleurGagnante
	
	autreCasEtPair: 
		li $s0, 1
		j finCouleurGagnante
			
	finCouleurGagnante:
		jr $ra

 

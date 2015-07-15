# Determine the pre/post scalar division settings required for PLL clock settings
# To satisfy requirements Fosc <= 80 MHz, 0.8MHz <= Fref <= 8.0MHz, 100MHz <= Fvco <= 200MHz
# Do this by printing out all m, n1, n2 combinations

ms = range(2, 514)
n1s = range(2, 34)
n2s = [2, 4, 8]

Fin = 7.37
Fosc_desired = 80
closest = {'Fosc': 0, 'Fvco': 0, 'Fref': 0, 'm': 0, 'n1': 0, 'n2': 0}
for m in ms:
	for n1 in n1s:
		for n2 in n2s:
			Fosc = Fin*m/n1/n2
			Fref = Fin/n1
			Fvco = Fin*m/n1
			if (Fosc<=80 and Fref<=8 and Fref>=0.8 and Fvco<=200 and Fvco>=100):
				if abs(Fosc_desired - Fosc) < abs(Fosc_desired-closest['Fosc']):
					closest['Fosc'] = Fosc
					closest['Fvco'] = Fvco
					closest['Fref'] = Fref
					closest['m'] = m
					closest['n1'] = n1
					closest['n2'] = n2
				if Fosc >= 40:
					print "Fosc = %f, Fvco = %f, Fref = %f, (m, n1, n2) = (%d, %d, %d)" % (Fosc, Fvco, Fref, m, n1, n2)
print "\n Closest to Fosc = %f \n Fosc = %f, (m, n1, n2) = (%d, %d, %d) (Fvco = %f  Fref = %f)" % \
	(Fosc_desired, closest['Fosc'], closest['m'], closest['n1'], closest['n2'], closest['Fvco'], closest['Fref'])

.rodata
.balign 32
.globl fwalk1piclength
.globl fwalk1picdata

fwalk1piclength:	.long	fwalk1picdataend - fwalk1picdata
fwalk1picdata:
.incbin "../include/fwalk1.jpg"
fwalk1picdataend:

.globl fwalk2piclength
.globl fwalk2picdata

fwalk2piclength:	.long	fwalk2picdataend - fwalk2picdata
fwalk2picdata:
.incbin "../include/fwalk2.jpg"
fwalk2picdataend:

.globl fwalk3piclength
.globl fwalk3picdata

fwalk3piclength:	.long	fwalk3picdataend - fwalk3picdata
fwalk3picdata:
.incbin "../include/fwalk3.jpg"
fwalk3picdataend:

.globl fwalk4piclength
.globl fwalk4picdata

fwalk4piclength:	.long	fwalk4picdataend - fwalk4picdata
fwalk4picdata:
.incbin "../include/fwalk4.jpg"
fwalk4picdataend:

.globl bwalk1piclength
.globl bwalk1picdata

bwalk1piclength:	.long	bwalk1picdataend - bwalk1picdata
bwalk1picdata:
.incbin "../include/bwalk1.jpg"
bwalk1picdataend:

.globl bwalk2piclength
.globl bwalk2picdata

bwalk2piclength:	.long	bwalk2picdataend - bwalk2picdata
bwalk2picdata:
.incbin "../include/bwalk2.jpg"
bwalk2picdataend:

.globl bwalk3piclength
.globl bwalk3picdata

bwalk3piclength:	.long	bwalk3picdataend - bwalk3picdata
bwalk3picdata:
.incbin "../include/bwalk3.jpg"
bwalk3picdataend:

.globl bwalk4piclength
.globl bwalk4picdata

bwalk4piclength:	.long	bwalk4picdataend - bwalk4picdata
bwalk4picdata:
.incbin "../include/bwalk4.jpg"
bwalk4picdataend:



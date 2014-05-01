stateTable[Q][Q][Q] = Q;
	stateTable[Q][P][Q] = P;
	stateTable[Q][R][Q] = Q;
	stateTable[Q][Z][Q] = Q;
	stateTable[Q][M][Q] = NA;
	stateTable[Q][X][Q] = Q;

	stateTable[Q][Q][P] = P;
	stateTable[Q][P][P] = P;
	stateTable[Q][R][P] = NA;
	stateTable[Q][Z][P] = NA;
	stateTable[Q][M][P] = NA;
	stateTable[Q][X][P] = P;

	stateTable[Q][Q][R] = Q;
	stateTable[Q][P][R] = NA;
	stateTable[Q][R][R] = Q;
	stateTable[Q][Z][R] = NA;
	stateTable[Q][M][R] = NA;
	stateTable[Q][X][R] = Q;

	stateTable[Q][Q][Z] = Q;
	stateTable[Q][P][Z] = NA;
	stateTable[Q][R][Z] = NA;
	stateTable[Q][Z][Z] = Q;
	stateTable[Q][M][Z] = NA;
	stateTable[Q][X][Z] = Q;

	stateTable[Q][Q][M] = NA;
	stateTable[Q][P][M] = NA;
	stateTable[Q][R][M] = NA;
	stateTable[Q][Z][M] = NA;
	stateTable[Q][M][M] = NA;
	stateTable[Q][X][M] = NA;

	stateTable[Q][Q][X] = Q;
	stateTable[Q][P][X] = P;
	stateTable[Q][R][X] = NA;
	stateTable[Q][Z][X] = Q;
	stateTable[Q][M][X] = NA;
	stateTable[Q][X][X] = NA;

	stateTable[Z][Q][Q] = NA;
	stateTable[Z][P][Q] = NA;
	stateTable[Z][R][Q] = Q;
	stateTable[Z][Z][Q] = P;
	stateTable[Z][M][Q] = Q;
	stateTable[Z][X][Q] = NA;

	stateTable[Z][Q][P] = NA;
	stateTable[Z][P][P] = Z;
	stateTable[Z][R][P] = NA;
	stateTable[Z][Z][P] = Z;
	stateTable[Z][M][P] = NA;
	stateTable[Z][X][P] = Z;

	stateTable[Z][Q][R] = Q;
	stateTable[Z][P][R] = NA;
	stateTable[Z][R][R] = Q;
	stateTable[Z][Z][R] = Q;
	stateTable[Z][M][R] = NA;
	stateTable[Z][X][R] = Q;

	stateTable[Z][Q][Z] = P;
	stateTable[Z][P][Z] = Z;
	stateTable[Z][R][Z] = Q;
	stateTable[Z][Z][Z] = F;
	stateTable[Z][M][Z] = Q;
	stateTable[Z][X][Z] = F;

	stateTable[Z][Q][M] = Q;
	stateTable[Z][P][M] = NA;
	stateTable[Z][R][M] = NA;
	stateTable[Z][Z][M] = Q;
	stateTable[Z][M][M] = Q;
	stateTable[Z][X][M] = Q;

	stateTable[Z][Q][X] = NA;
	stateTable[Z][P][X] = NA;
	stateTable[Z][R][X] = Q;
	stateTable[Z][Z][X] = F;
	stateTable[Z][M][X] = Q;
	stateTable[Z][X][X] = NA;

	stateTable[P][Q][Q] = Z;
	stateTable[P][P][Q] = Z;
	stateTable[P][R][Q] = R;
	stateTable[P][Z][Q] = R;
	stateTable[P][M][Q] = NA;
	stateTable[P][X][Q] = Z;

	stateTable[P][Q][P] = Z;
	stateTable[P][P][P] = NA;
	stateTable[P][R][P] = Z;
	stateTable[P][Z][P] = Z;
	stateTable[P][M][P] = NA;
	stateTable[P][X][P] = NA;

	stateTable[P][Q][R] = R;
	stateTable[P][P][R] = Z;
	stateTable[P][R][R] = Z;
	stateTable[P][Z][R] = NA;
	stateTable[P][M][R] = NA;
	stateTable[P][X][R] = Z;

	stateTable[P][Q][Z] = R;
	stateTable[P][P][Z] = Z;
	stateTable[P][R][Z] = NA;
	stateTable[P][Z][Z] = Z;
	stateTable[P][M][Z] = NA;
	stateTable[P][X][Z] = Z;

	stateTable[P][Q][M] = NA;
	stateTable[P][P][M] = NA;
	stateTable[P][R][M] = NA;
	stateTable[P][Z][M] = NA;
	stateTable[P][M][M] = NA;
	stateTable[P][X][M] = NA;

	stateTable[P][Q][X] = NA;
	stateTable[P][P][X] = NA;
	stateTable[P][R][X] = Z;
	stateTable[P][Z][X] = Z;
	stateTable[P][M][X] = NA;
	stateTable[P][X][X] = NA;

	stateTable[M][Q][Q] = NA;
	stateTable[M][P][Q] = NA;
	stateTable[M][R][Q] = NA;
	stateTable[M][Z][Q] = NA;
	stateTable[M][M][Q] = NA;
	stateTable[M][X][Q] = NA;

	stateTable[M][Q][P] = NA;
	stateTable[M][P][P] = NA;
	stateTable[M][R][P] = NA;
	stateTable[M][Z][P] = NA;
	stateTable[M][M][P] = NA;
	stateTable[M][X][P] = NA;

	stateTable[M][Q][R] = NA;
	stateTable[M][P][R] = NA;
	stateTable[M][R][R] = R;
	stateTable[M][Z][R] = Z;
	stateTable[M][M][R] = NA;
	stateTable[M][X][R] = NA;

	stateTable[M][Q][Z] = NA;
	stateTable[M][P][Z] = NA;
	stateTable[M][R][Z] = Z;
	stateTable[M][Z][Z] = NA;
	stateTable[M][M][Z] = NA;
	stateTable[M][X][Z] = NA;

	stateTable[M][Q][M] = NA;
	stateTable[M][P][M] = NA;
	stateTable[M][R][M] = NA;
	stateTable[M][Z][M] = NA;
	stateTable[M][M][M] = NA;
	stateTable[M][X][M] = NA;

	stateTable[M][Q][X] = NA;
	stateTable[M][P][X] = NA;
	stateTable[M][R][X] = NA;
	stateTable[M][Z][X] = NA;
	stateTable[M][M][X] = NA;
	stateTable[M][X][X] = NA;

	stateTable[R][Q][Q] = NA;
	stateTable[R][P][Q] = NA;
	stateTable[R][R][Q] = R;
	stateTable[R][Z][Q] = P;
	stateTable[R][M][Q] = Z;
	stateTable[R][X][Q] = NA;

	stateTable[R][Q][P] = NA;
	stateTable[R][P][P] = NA;
	stateTable[R][R][P] = M;
	stateTable[R][Z][P] = R;
	stateTable[R][M][P] = M;
	stateTable[R][X][P] = NA;

	stateTable[R][Q][R] = R;
	stateTable[R][P][R] = M;
	stateTable[R][R][R] = NA;
	stateTable[R][Z][R] = NA;
	stateTable[R][M][R] = M;
	stateTable[R][X][R] = NA;

	stateTable[R][Q][Z] = P;
	stateTable[R][P][Z] = R;
	stateTable[R][R][Z] = NA;
	stateTable[R][Z][Z] = NA;
	stateTable[R][M][Z] = R;
	stateTable[R][X][Z] = NA;

	stateTable[R][Q][M] = Z;
	stateTable[R][P][M] = M;
	stateTable[R][R][M] = M;
	stateTable[R][Z][M] = R;
	stateTable[R][M][M] = M;
	stateTable[R][X][M] = NA;

	stateTable[R][Q][X] = NA;
	stateTable[R][P][X] = NA;
	stateTable[R][R][X] = NA;
	stateTable[R][Z][X] = NA;
	stateTable[R][M][X] = NA;
	stateTable[R][X][X] = NA;
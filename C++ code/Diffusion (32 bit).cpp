/*****************************************************************************************

	Diffusion Along a Circle
	(Canonical Ensemble)
	Eigensystem Approach
	32 bit version

	Written by:  Christian Bracher
	Version   :  0.31
	Date      :  March 19, 2004
	Tested    :  July 2, 2013

*****************************************************************************************/

/* *** INITIALIZATION ROUTINES *** */

/* Required Libraries */
	#include<fstream>
	#include<iostream>
	#include<string>
	#include<complex>
	#include<cstdlib>

	using namespace std;

/* Version Info */
	const char *VersionSpec = "0.31";
	const char *VersionDate = "March 18, 2004";


/* *** GLOBAL VARIABLES *** */

/* Mathematical Constants */
	const double Pi = 4.0 * atan(1.0);
	complex<double> ii = complex<double>(0.0,1.0);


/* *** DEFAULT VALUES ***/

/* Jumping Rates */
	double RateA = 1.00;
	double RateB = 1.00;
	double RateC = 1.00;
	double RateD = 1.00;

/* Limits of Temporal Evolution */
	double StartTime = 0.0;
	double StopTime = 10.0;

/* Number of Steps in Evolution */
	long Steps = 100;

/* Precision of Output (Digits) */
	int OutputPrecision = 6;


/* *** LIMITS *** */

/* Maximum Number of Primitive Patterns */
	long MaxPrimNum = 8192;

/* Maximum Number of Comparison Patterns */
	long MaxAvgPatNum = 512;


/* *** SWITCHES - DEFAULTS *** */

/* Omit Unitary Transform */
	bool EigenvaluesOnly = false;

/* Perform Calculation in Single q Subspace only */
	bool SingleQSubspace = false;

/* Output Temporal Evolution of Averages */
	bool Evolution = true;

/* Use Logarithmic Time Scale */
	bool LogScale = false;

/* Output One-Atom Averages */
	bool OneAtom = true;

/* Output Two-Atom Averages */
	bool TwoAtom = false;

/* Output Custom Pattern Averages */
	bool CustomPattern = false;

/* Output Equilibrium Averages */
	bool EquilibriumAverage = false;

/* Show Deviation From Equilibrium Averages */
	bool ShowDeviation = false;

/* Use Fixed Float Format for Data Output */
	bool FixedDataFormat = true;

/* Output Ordered Eigenvalues */
	bool ShowEigenvalues = false;

/* Output Eigenvectors */
	bool ShowEigenvectors = false;

/* Output Left/Right Eigenvectors of Unsymmetrized Matrix */
	bool ShowLeftEV = false;
   bool ShowRightEV = false;

/* Output Weight of Eigenstate in Initial Configuration */
	bool ShowEVWeight = false;

/* Show Contribution to One-Site Momentum Average <q> */
   bool ShowQContribution = false;

/* Post-Symmetrize Eigenvectors */
	bool SymmetrizeEigenvectors = false;

/* Check Accuracy of Diagonalization */
	bool CheckAccuracy = false;

/* Output Primitive Patterns */
	bool ShowPrimitives = false;

/* Output Rate Coefficent Matrix */
	bool ShowRateMatrix = false;

/* Load Transformation Block Data */
	bool LoadBlockData = false;

/* Save Transformation Block Data */
	bool SaveBlockData = false;


/* *** AUXILIARY VARIABLES AND FIELDS *** */

/* Initial State of System (must be pure) */
/* "o" Denotes Atom, "." Denotes Hole     */
	string InitialState;

/* Pattern Template for Averaging Purposes */
	string *AveragePattern;
	int AveragePatternNumber;

/* Pattern Matching Flag Array Template */
	bool *DoesMatch;

/* Number of Sites (MUST BE PRIME) */
	long p;

/* Number of Atoms */
	long k;

/* Number of Primitive Patterns */
	long PrimNum;

/* Number of Palindromic Patterns */
	long PalinNum;

/* The Momentum Identifier */
	long q;

/* Selected q Subspace */
   int QSubspace;

/* Powers of 2 */
	unsigned long *exp2pow;

/* Roots of Unity */
	complex<double> *UnityRoot;

/* Output Filenames */
	string OutputFilename;
	string InfoFilename;
	string DataFilename;

/* Block Data Filename */
	string BlockFilename;

/* *** FUNCTION DECLARATION HEADER *** */

   string ConvertIntegerToString(int Number);

/* *** ERROR MESSAGE HANDLER *** */

/* Show an Error Message And Abort */
	void ErrorMessage(string Message)
	{
		cerr << "ERROR:  " << Message.c_str() << ".\n\n";
		exit(0);
	}


/* *** VARIABLE CLASSES ***/

	struct Pattern
	{

	/* Assignment Operator: Direct, by Value */
		void operator=(long Value)
		{
			Code = Value;
		}

	/* Assignment Operator: Indirect, by Graphical String */
		void operator=(string Graphics)
		{
		/* Check Size of Pattern */
			if (Graphics.size() != p)
			{
				cerr << "ERROR:  Illegal Pattern Size\n\n";
				exit(0);
			}

		/* Assign Code to Pattern */
			Code=0;
			string Aux;

			for (int i=p; i > 0; --i)
			{
				Aux.assign(Graphics,i-1,1);
				Code *= 2;

				if ((Aux == ".") || (Aux == "o"))
				{
				/* Hole or Atom */
					if (Aux == "o")  ++Code;

				}
				else
				{
				/* Unrecognized Symbol */
					cerr << "ERROR:  Illegal Symbol in Pattern\n\n";
					exit(0);
				}
			}
		}

	/* Incremental Rotation Operator ++:  Rotate to Higher Value */
		void operator ++()
		{
			Code *= 2;
			if ((Code & exp2pow[p]) != 0)
			{
				Code &= (~exp2pow[p]);
				++Code;
			}
		}

	/* Incremental Rotation Operator --:  Rotate to Lower Values */
		void operator --()
		{
			if ((Code & 1) != 0)
			{
				Code |= exp2pow[p];
			}
			Code /= 2;
		}

	/* Default Constructor */
		Pattern()
		{
			Code = 0;
		}

	/* Explicit Constructor - by Value */
		Pattern(unsigned long Value)
		{
			Code = Value;
		}

	/* Explicit Constructor - Graphical */
	   Pattern(string Graphics)
		{
		/* Check Size of Pattern */
			if (Graphics.size() != p)
			{
				cerr << "ERROR:  Illegal Pattern Size\n\n";
				exit(0);
			}

		/* Assign Code to Pattern */
			Code=0;
			string Aux;

			for (int i=p; i > 0; --i)
			{
				Aux.assign(Graphics,i-1,1);
				Code *= 2;

				if ((Aux == ".") || (Aux == "o"))
				{
				/* Hole or Atom */
					if (Aux == "o")  ++Code;
				}
				else
				{
				/* Unrecognized Symbol */
					cerr << "ERROR:  Illegal Symbol in Pattern\n\n";
					exit(0);
				}
			}
		}

	/* Extract Number of Atoms in Pattern */
		int AtomNum()
		{
			int Aux = 0;
			unsigned long zz = Code;
			for (int i=0; i < p; ++i)
			{

				if ((zz % 2) == 1) ++Aux;
				zz = zz / 2;
			}
			return Aux;
		}

	/* Extract Pattern Sum */
		int PatternSum()
		{
			int Aux = 0;
			unsigned long zz = Code;
			for (int i=0; i < p; ++i)
			{
				if ((zz & 1) == 1) Aux += i;
				zz = zz / 2;
			}
			return (Aux % p);
		}

	/* Find Primitive Pattern and Shift */
		int Primitive()
		{
			int Aux = 0;

			while (PatternSum() != 0)
			{
				++Aux;
				if ((Code % 2) == 1) (Code |= exp2pow[p]);
				Code = Code / 2;
			}
			return (Aux % p);
		}

	/* Extract Position of Element nu */
		int Element(int nu)
		{
			int Aux1 = 0;
			int Aux2 = -1;
			unsigned long zz = Code;
			while (Aux1 < nu)
			{
				if ((zz & 1) == 1) ++Aux1;
				zz = zz / 2;
				++Aux2;
			}
			return Aux2;
		}

	/* *** Increment/Decrement Functions *** */

	/* Is Increment Possible? */
		bool IncrementSiteBlocked(int nu)
		{
			bool HasImmediateNeighbour = false;
			int Aux = Element(nu);
			if ((Code & exp2pow[(Aux + 1) % p]) != 0)
			{
				HasImmediateNeighbour = true;
			}
			return HasImmediateNeighbour;
		}

	/* Increment Position of Element nu,
	   Function Returns Type of Jump (A,B,C,D = 0,1,2,3) */
		int Increment(int nu)
		{
			int Aux = Element(nu);

			Code &= (~exp2pow[Aux]);
			Code |= exp2pow[(Aux + 1) % p];

			unsigned long Aux1 = (Code & exp2pow[(Aux + p - 1) % p]);
			unsigned long Aux2 = (Code & exp2pow[(Aux + 2) % p]);

			int Type = 0;
			if (Aux1 != 0) ++Type;
			if (Aux2 != 0) Type += 2;

			return Type;
		}

	/* Is Decrement Possible? */
		bool DecrementSiteBlocked(int nu)
		{
			bool HasImmediateNeighbour = false;
			int Aux1 = Element(nu);
			int Aux2 = Element(((nu + k - 2) % k) + 1);
			if (((Aux1 - Aux2 + p) % p) == 1)
			{
				HasImmediateNeighbour = true;
			}
			return HasImmediateNeighbour;
		}

	/* Decrement Position of Element nu
	   Function Returns Type of Jump (A,B,C,D = 0,1,2,3) */
		int Decrement(int nu)
		{
			int Aux = Element(nu);
			Code &= (~exp2pow[Aux]);
			Code |= exp2pow[(Aux + p - 1) % p];

			unsigned long Aux1 = (Code & exp2pow[(Aux + 1) % p]);
			unsigned long Aux2 = (Code & exp2pow[(Aux + p - 2) % p]);

			int Type = 0;
			if (Aux1 != 0) ++Type;
			if (Aux2 != 0) Type += 2;

			return Type;
		}

	/* Effective Number of C-Type Jumps Required to Collapse Pattern */
		int CollapsingNumber()
		{
			int CNum = 0;
			Pattern Aux = Code;
			for (int nu=2; nu <= k; ++nu)
			{
				while (Aux.DecrementSiteBlocked(nu) == false)
				{
					switch (Aux.Decrement(nu))
					{
					case 1:
						--CNum;
						break;
					case 2:
						++CNum;
						break;
					default:
						break;
					};
				}
			}

			return CNum;
		}

	/* *** Mirror Reflection Routines *** */

	/* Mirror Reflection of Pattern */
		void Mirror()
		{
			unsigned long Aux = (Code & 1);

			for (long i=1; i < p; ++i)
			{
				if ((Code & exp2pow[i]) == exp2pow[i])
				{
					Aux |= exp2pow[p-i];
				}
			}

			Code = Aux;
			return;
		}

	/* Check for Palindromic Pattern */
		bool IsPalindromic()
		{
			bool Palindromic = false;

			Pattern Aux = Code;

			Aux.Mirror();
			if (Aux.Code == Code)  Palindromic = true;

			return Palindromic;
		}

	/* *** SEARCH FOR MATCHING SUBPATTERNS *** */

	/* Check For Matching Pattern */
		bool Match(string Comparison)
		{
			bool IsMatch = false;

		/* Check If Subpattern Has Matching Size */
			if (Comparison.size() != p)
			{
				cerr << "ERROR:  Comparison pattern does not match size\n\n";
				exit(0);
			}

		/* Create Separate Codes For Atoms And Holes in Subpattern */
			unsigned long AtomCode = 0;
			unsigned long HoleCode = 0;
			string Aux;

			for (int i=p; i > 0; --i)
			{
				Aux.assign(Comparison,i-1,1);
				AtomCode *= 2;
				HoleCode *= 2;

			/* "x" Denotes Undefined (Either) Type */
				if ((Aux != ".") && (Aux != "o") && (Aux != "x"))
				{
				/* Unrecognized Symbol */
					cerr << "ERROR:  Illegal Symbol in Pattern\n\n";
					exit(0);
				}

			/* Atom */
				if (Aux == "o")  ++AtomCode;

			/* Hole */
				if (Aux == ".")  ++HoleCode;
			}

		/* Check for Matching Pattern */
			if (((Code & AtomCode) == AtomCode) && ((Code & HoleCode) == 0))
			{
				IsMatch = true;
			}

			return IsMatch;
		}

	/* Count Number of Occurrences of Subpattern in Primitive */
		int Multiplicity(string Comparison)
		{
			Pattern Copy = Code;

		/* Loop Through Pattern And Compare */
			int Number = 0;

			for (int i=0; i < p; ++i)
			{
			/* Test For Matching Pattern */
				if (Copy.Match(Comparison) == true)
				{
					++Number;
				}

			/* Rotate Pattern by One Site */
				++Copy;
			}

			return Number;
		}

	/* *** DEBUGGING ROUTINES *** */

	/* Return a String Containing The Atom Positions (Numerical) */
		string Structure()
		{
			string Comp;
			int i;
			for (i = 1; i <= k; ++i)
			{
				Comp.append(ConvertIntegerToString(Element(i)));
				if (i < k) Comp.append(" ");
			}

			return Comp;
		}

	/* Return a String Containing The Atom Positions (Graphical) */
		string Graphics()
		{
			string Comp;
			for (int i = 0; i < p; ++i)
			{
				if ((Code & exp2pow[i]) == exp2pow[i])
				{
					Comp.append("o");
				}
				else
				{
					Comp.append(".");
				}
			}

			return Comp;
		}


	/* *** VARIABLES *** */

	/* Binary Pattern Storage */
		unsigned long Code;
	};

	struct DecayCoefficients
	{

	/* Assignment Operator */
		void operator=(DecayCoefficients Template)
		{
			RateCoeffA = Template.RateCoeffA;
			RateCoeffB = Template.RateCoeffB;
			RateCoeffC = Template.RateCoeffC;
			RateCoeffD = Template.RateCoeffD;
		}

	/* Default Constructor */
		DecayCoefficients()
		{
			RateCoeffA = 0;
			RateCoeffB = 0;
			RateCoeffC = 0;
			RateCoeffD = 0;
		}

	/* Explicit Constructor */
		DecayCoefficients(char A, char B, char C, char D)
		{
			RateCoeffA = A;
			RateCoeffB = B;
			RateCoeffC = C;
			RateCoeffD = D;
		}

		char RateCoeffA;
		char RateCoeffB;
		char RateCoeffC;
		char RateCoeffD;
	};

/* *** GLOBAL ARRAYS ***/

/* Storage for "Primitive" Patterns */
	Pattern *Primitive;

/* Storage for Mirror Image Assignments */
	int *MirrorImage;

/* Storage for Coefficients */
	DecayCoefficients *Diagonal;
	DecayCoefficients *Forward;
	DecayCoefficients *Backward;

/* Storage for Eigenvector */
	double *EqEV;

/* *** PATTERN IDENTIFICATION *** */

/* Find a Primitive Pattern in the Array */
	long PatternPosition(Pattern Prim)
	{
		unsigned long Aux1 = 0;
		unsigned long Aux2 = PrimNum;
		unsigned long Current;

		do
		{
			Current = (Aux1 + Aux2) / 2;
			if (Prim.Code > Primitive[Current].Code)
			{
				Aux1 = Current;
			}
			else
			{
				Aux2 = Current;
			}
		}
		while (Prim.Code != Primitive[Current].Code);

		return Current;
	}

/* *** SYMMETRY PROJECTION SUBROUTINES *** */

/* Project a Real Vector Onto the Symmetric Subspace, Return Norm */
	double ProjectSymm(double *Vector, double* Proj)
	{
		double Norm = 0.0;

		for (long i=0; i < PrimNum; ++i)
		{
		/* Create Mirror Image of Pattern */
			Pattern Aux = Primitive[i].Code;
			Aux.Mirror();

		/* Lookup Mirror Pattern in List */
			long Image = PatternPosition(Aux);

		/* Add Contributions */
			Proj[i] = 0.5 * (Vector[i] + Vector[Image]);

		/* Calculate Norm */
			Norm += Proj[i] * Proj[i];
		}

		return Norm;
	}

/* Project a Real Vector Onto the Antisymmetric Subspace, Return Norm */
	double ProjectAnti(double *Vector, double* Proj)
	{
		double Norm = 0.0;

		for (long i=0; i < PrimNum; ++i)
		{
		/* Create Mirror Image of Pattern */
			Pattern Aux = Primitive[i].Code;
			Aux.Mirror();

		/* Lookup Mirror Pattern in List */
			long Image = PatternPosition(Aux);

		/* Add Contributions */
			Proj[i] = 0.5 * (Vector[i] - Vector[Image]);

		/* Calculate Norm */
			Norm += Proj[i] * Proj[i];
		}

		return Norm;
	}

/* Check For Symmetric Pattern Vectors (to float accuracy) */
/* (call with position &Vector[...] as argument) */
	bool VectorIsSymmetric(double *Vector)
	{
		bool Test = false;

	/* Required Numerical Accuracy */
		double AccuSq = 1e-15;

	/* Create Projection on Antisymmetric Subspace */
		double *AntiVec = new double[PrimNum];

	/* Check Deviation From Original Vector */
		double Dev = ProjectAnti(&Vector[0], &AntiVec[0]);

	/* Free Memory */
		delete[] AntiVec;

	/* Check Whether Symmetric Within Accuracy Limits */
		if (Dev < AccuSq)  (Test = true);

		return Test;
	}

/* Check For Antisymmetric Pattern Vectors (to float accuracy) */
/* (call with position &Vector[...] as argument) */
	bool VectorIsAntisymmetric(double *Vector)
	{
		bool Test = false;

	/* Required Numerical Accuracy */
		double AccuSq = 1e-15;

	/* Create Projection on Symmetric Subspace */
		double *SymmVec = new double[PrimNum];

	/* Check Deviation From Original Vector */
		double Dev = ProjectSymm(&Vector[0], &SymmVec[0]);

	/* Free Memory */
		delete[] SymmVec;

	/* Check Whether Symmetric Within Accuracy Limits */
		if (Dev < AccuSq)  (Test = true);

		return Test;
	}


/* *** ELIMINATION OF COMMON SIGNS/PHASES *** */

/* Remove a Common Sign From A Real Vector */
	void RemoveCommonSign(double *Vector)
	{
		double Aux = 0.0;
		long i;

	/* Sum All Components */
		for (i=0; i < PrimNum; ++i)
		{
			Aux += Vector[i];
		}

	/* Remove Sign, If Necessary */
		if (Aux < 0.0)
		{
			for (i=0; i < PrimNum; ++i)
			{
				Vector[i] = -Vector[i];
			}
		}
	}

/* Remove a Common Phase From A Complex Vector */
	void RemoveCommonPhase(complex<double> *Vector)
	{
		complex<double> AuxC = complex<double>(0.0, 0.0);
		long i;

	/* Sum All Components */
		for (i=0; i < PrimNum; ++i)
		{
			AuxC += Vector[i];
		}

	/* Determine Unitary Phase Factor of Sum */
		double Aux = sqrt(norm(AuxC));
		if (Aux > 0.0)
		{
		/* Inverse of Unitary Phase Factor */
			AuxC = conj(AuxC) / Aux;
		}
		else
		{
		/* Vector Sums To Zero; Elimination Procedure Fails */
			AuxC = complex<double>(1.0, 0.0);
		}

	/* Remove Phase */
		for (i=0; i < PrimNum; ++i)
		{
			Vector[i] *= AuxC;
		}
	}


/* *** AVERAGE CALCULATION PROCEDURES *** */

/* Calculate the Average of a Predefined Pattern From the Pattern Probability Vector */
/* (call with &ResultVec[0] as argument) */
	double Average(string Test, double *Prob)
	{
		double Sum = 0.0;
		long i,nu;

		for (i=0; i < PrimNum; ++i)
		{
			Pattern Aux = Primitive[i];

			for (nu=0; nu < p; ++nu)
			{
				if (Aux.Match(Test) == true)
				{
					Sum += Prob[nu * PrimNum + i];
				}
				++Aux;
			}
		}

		return Sum;
	}

/* Calculate the Equilibrium Average of a Predefined Pattern */
	double EqAverage(string Test)
	{
		double Sum = 0.0;
		long i;

		for (i=0; i < PrimNum; ++i)
		{
			Sum += EqEV[i] * Primitive[i].Multiplicity(Test);
		}

		return Sum;
	}

/* *** INTEGER/MODULO ARITHMETICS *** */

/* A Simple Primality Test */
	bool IsPrime(long Test)
	{
		bool PrimeTest = true;
		int i;

		for (i=2; i < Test; ++i)
		{
			if ((Test % i) == 0)  PrimeTest = false;
		}

		return PrimeTest;
	}

/* Modulo Division */
	long ModuloDiv(long Numerator, long Denominator)
	{
		long Result = 0;
		long Aux = 0;

		while (Aux != Numerator)
		{
			++Result;
			Aux = ((Aux + Denominator) % p);
		}

		return Result;
	}

/* *** MATRIX MANIPULATION *** */

/* Global Variable: Dimension of Matrices and Vectors */
	long MatrixDim;

/* Calculate Array Element from Matrix Position */
	inline long Element(long Row, long Column)
	{
		return (Row * MatrixDim + Column);
	}

/* *** MATHEMATICAL ROUTINES (SYMMETRIC PROBLEMS) *** */

/* *** Householder Reduction to Tridiagonal Form (Symmetric Matrices)  */
/* *** Input:  Address of Array Containing Symmetric Matrix            */
/*             Addresses of Vector Arrays for Diagonal and             */
/*             Extradiagonal Elements (all type "double")              */
/* *** Output: Diagonal and Extradiagonal Elements                     */
/*             Right-Hand Orthogonal Transformation Matrix             */
/*             (replaces symmetric matrix) --- if desired              */
/* *** (see Stoer/Bulirsch, Ch. 6.5.1)                                 */
/*                                                                     */
/* *** Calling Convention:                                             */
/*     HouseholderSymm(&Matrix[0], &Diagonal[0], &ExtraDiagonal[0]);   */
/*                                                                     */
/* *** Global Variables Required:                                      */
/*     MatrixDim --- Dimension of Input Matrix/Vectors                 */
/*     EigenvaluesOnly --- Omit Calculation of Orthogonal Transform    */
/* *** Required Function Calls:                                        */
/*     inline long Element(long Row, long Column) ---				   */
/*     Position of Matrix Element (Row,Column) in Matrix Arrays        */

	void HouseholderSymm(double *Matr, double *Diag, double *ExDiag)
	{
		int i,j,k;
		double Sum,Aux,Sign,Scalar;
		long iOffset,jOffset,kOffset;

	/* *** Perform Householder Transformations *** */
		cerr << "Householder tridiagonalization ";

		for (i = MatrixDim - 1; i > 1; --i)
		{
		/* Offset */
			iOffset = i * MatrixDim;

		/* Extract Diagonal Element */
			Diag[i] = Matr[iOffset + i];

		/* Calculate Norm of Partial Row/Column; Symmetrize Matrix
		   (dispose of numerical deviations) */
			Sum = 0.0;
			for (k = 0; k < i; ++k)
			{
				Matr[iOffset + k] = Matr[k * MatrixDim + i];
				Sum += Matr[iOffset + k] * Matr[iOffset + k];
			}

		/* No Action Required If Already Empty */
			if (Sum == 0.0)
			{
				ExDiag[i] = Matr[Element(i-1,i)];
				Matr[Element(i,i)] = 0.0;
			}
			else
			{
			/* Determine Sign Factor */
				Sign = 1.0;
				Aux = fabs(Matr[Element(i-1, i)]);

				if (Aux > 0.0)
				{
					Sign = Matr[Element(i-1, i)] / Aux;
				}

			/* Superdiagonal Element */
				ExDiag[i] = - sqrt(Sum) * Sign;

			/* Partial Vector u = Matrix[i] - ExDiag[i] (stored in Matrix) */
				Matr[Element(i-1, i)] -= ExDiag[i];
				Matr[Element(i, i-1)] -= ExDiag[i];

			/* Calculate Inverted (one-half) Norm of u and Store in Diag Part of Matrix */
				Aux = 1.0 / (Sum + sqrt(Sum) * Aux);
				Matr[Element(i, i)] = Aux;

		/* Partial Vector p = Matrix * u / Norm, Stored in Unused Part of SuperDiag[i] */
				for (k = 0; k < i; ++k)
				{
				/* Offset */
					kOffset = k * MatrixDim;

					ExDiag[k] = 0.0;
					for (j = 0; j < i; ++j)
					{
						ExDiag[k] += Matr[kOffset + j] * Matr[j * MatrixDim + i];
					}
					ExDiag[k] *= Aux;
				}

		/* Scalar s = u^+ * p / Norm */
				Scalar = 0.0;

				for (k = 0; k < i; ++k)
				{
					Scalar += Matr[iOffset + k] * ExDiag[k];
				}
				Scalar *= (0.5 * Aux);

		/* Vector q = p - s * u, in ExDiag[i] */
				for (k = 0; k < i; ++k)
				{
					ExDiag[k] -= Scalar * Matr[k * MatrixDim + i];
				}

		/* Householder Transformation on Partial Matrix */
				for (k = 0; k < i; ++k)
				{
				/* Offset */
					kOffset = k * MatrixDim;

					for (j = 0; j < i; ++j)
					{
					/* Offset */
						jOffset = j * MatrixDim;

						Matr[jOffset + k] -= (Matr[jOffset + i] * ExDiag[k]
											   + Matr[iOffset + k] * ExDiag[j]);
					}
				}
			}
		/* Display Progress */
			cerr << ".";
		}

		cerr << " done.\n";

	/* Readout Leftover 2 x 2 Matrix */
		Diag[0] = Matr[Element(0,0)];
		ExDiag[0] = 0.0;

	/* Take Care of 1 x 1 - "Matrices" */
		if (MatrixDim > 1)
		{
			Diag[1] = Matr[Element(1,1)];
			ExDiag[1] = Matr[Element(0,1)];
		}

	/* *** ASSEMBLE TRANSFORMATION MATRIX *** */

	/* Transformation Only If Desired */
		if (EigenvaluesOnly == false)
		{
			cerr << "Orthogonal transformation ";

		/* Step 1:  Initialize Matrix */
			Matr[Element(0,0)] = 1.0;

		/* Take Care of 1 x 1 - "Matrices" */
			if (MatrixDim > 1)
			{
				Matr[Element(1,0)] = 0.0;
				Matr[Element(0,1)] = 0.0;
				Matr[Element(1,1)] = 1.0;
			}

		/* Step 2:  Recursive Multiplication */
			for (i = 2; i < MatrixDim; ++i)
			{
			/* Offset */
				iOffset = i * MatrixDim;

			/* Readout Inverse Norm */
				Aux = Matr[iOffset + i];

			/* Loop Through Rows */
				for (j = 0; j < i; ++j)
				{
					Scalar = 0.0;

				/* Offset */
					jOffset = j * MatrixDim;

				/* Loop Through Columns */
					for (k = 0; k < i; ++k)
					{
						Scalar += Matr[jOffset + k] * Matr[k * MatrixDim + i];
					}
					Scalar *= Aux;

					for (k = 0; k < i; ++k)
					{
						Matr[jOffset + k] -= Scalar * Matr[iOffset + k];
					}
				}

			/* Clean Matrix Row And Column */
				for (j = 0; j < i; ++j)
				{
					Matr[iOffset + j] = 0.0;
					Matr[j * MatrixDim + i] = 0.0;
				}

				Matr[iOffset + i] = 1.0;

			/* Display Progress */
				cerr << ".";
			}

		/* Finish up */
			cerr << " done.\n";
		}

		return;
	}

/* *** Diagonalization of Tridiagonal Symmetric Matrices               */
/*     QR Algorithm with Explicit Shift                                */
/* *** Input:  Address of Array Containing Orthogonal Transformation   */
/*             from Previous Householder Tridiagonalization            */
/*             (or a unit matrix, if no tridiagonalization required)   */
/*             Addresses of Vector Arrays for Diagonal and             */
/*             Extradiagonal Elements (all type "double")              */
/* *** Output: Eigenvalues (replace diagonal elements)                 */
/*             Right-Hand Orthogonal Transformation Matrix             */
/*             (eigenvectors are stored in rows)                       */
/* *** (see Stoer/Bulirsch, Ch. 6.6.4, 6.6.5)                          */
/*                                                                     */
/* *** Calling Convention:                                             */
/*     QRSymm(&Matrix[0], &Diagonal[0], &ExtraDiagonal[0]);            */
/*                                                                     */
/* *** Global Variables Required:                                      */
/*     MatrixDim --- Dimension of Input Matrix/Vectors                 */
/* *** Required Function Calls:                                        */
/*     inline long Element(long Row, long Column) ---				   */
/*     Position of Matrix Element (Row,Column) in Matrix Arrays        */

	void QRSymm(double *Matr, double *Diag, double *ExDiag)
	{
		int i,j,k,Count;
		double Aux,Shift,SquareRoot;
		double theta,t,c,s;
		double OldCos;
		double SuperDiagNorm1,SuperDiagNorm2,Ratio;
		bool Flag;

	/* Temporary Element Storage Allocation */
		double *Cosine  = new double[MatrixDim];
		double *Sine    = new double[MatrixDim];
		double *OffDiag = new double[MatrixDim];

	/* Maximum Number of Iterations */
		int MaxIter = 30;

	/* Accuracy Goal for Off-Diagonal Elements */
		double Accu = 1e-16;

	/* Element Counter */
		i = MatrixDim - 1;

	/* Set "Surplus" Element */
		ExDiag[0] = 0.0;

	/* Start Message */
		cerr << "QR Diagonalization ";

	/* Successive Diagonalization of Lower Right Elements */
		while (i > 0)
		{
		/* Test Whether Diagonalization is Necessary */
			SuperDiagNorm1 = fabs(ExDiag[i]);
			SuperDiagNorm2 = fabs(ExDiag[i-1]);

			Ratio = 1.0 / (SuperDiagNorm1 + SuperDiagNorm2 + Accu);

			if (SuperDiagNorm1 < SuperDiagNorm2)
			{
				Ratio *= SuperDiagNorm1;
				Flag = true;
			}
			else
			{
				Ratio *= SuperDiagNorm2;
				Flag = false;
			}

			Count = 0;

			while ((i>1) && (Ratio > Accu))
			{
			/* Iteration Counter and Error Check */
				++Count;
				if (Count > MaxIter)
				{
					cout << "ERROR in routine QR():  No convergence \n\n";
					exit(0);
				}

			/* Guess for Explicit Shift (Stoer/Bulirsch 6.6.5.7b) */
				Aux = .5 * (Diag[i] - Diag[i-1]);
				Shift = .5 * (Diag[i] + Diag[i-1]);
				SquareRoot = sqrt(Aux * Aux + SuperDiagNorm1 * SuperDiagNorm1);

				if (Aux > 0)
				{
					Shift += SquareRoot;
				}
				else
				{
					Shift -= SquareRoot;
				}

			/* Shift All Diagonal Elements */
				for (j = 0; j <= i; ++j)
				{
					Diag[j] -= Shift;
				}

			/* Sequence of Givens Rotations to Annihilate Lower Subdiagonal */
				OldCos = 1.0;

				for (j = 0; j < i; ++j)
				{
				/* Prepare Subdiagonal Elements */
					if (ExDiag[j+1] * ExDiag[j+1] > 0.0)
					{
					/* Givens Rotation */
						Aux = 1.0 / sqrt(ExDiag[j+1] * ExDiag[j+1]
							+ Diag[j] * Diag[j]);

					/* Parameters to Store */
						Cosine[j]  = Diag[j] * Aux;
						Sine[j]    = ExDiag[j+1] * Aux;
						OffDiag[j] = Cosine[j] * OldCos * ExDiag[j+1]
									 + Sine[j] * Diag[j+1];

					/* Actual Rotation (off-diagonal elements not required) */
						Diag[j]    = (Cosine[j] * Diag[j] + Sine[j] * ExDiag[j+1]);
						Diag[j+1]  = (Cosine[j] * Diag[j+1]
										  - Sine[j] * OldCos * ExDiag[j+1]);
					}
					else
					{
					/* No Rotation Required, Store Identity */
						Cosine[j]  = 1.0;
						Sine[j]    = 0.0;
						OffDiag[j] = 0.0;
					}

					OldCos = Cosine[j];
				}

			/* Sequence of Conjugate Givens Rotations to Complete Orthogonal Transform */

			/* Pointers Into Unitary Matrix */
				long Ptr  = 0;
				long pPtr = MatrixDim;

				for (j = 0; j < i; ++j)
				{
				/* Givens Rotation */
					Diag[j]    = Cosine[j] * Diag[j] + Sine[j] * OffDiag[j];
					ExDiag[j+1] = Sine[j] * Diag[j+1];
					Diag[j+1]  *= Cosine[j];

				/* Perform Rotation in Unitary Transformation Matrix (If Required) */
					if (EigenvaluesOnly == false)
					{
						for (k = 0; k < MatrixDim; ++k)
						{
						/* Temporary Storage */
							Aux = Cosine[j] * Matr[pPtr] - Sine[j] * Matr[Ptr];

						/* Unitary Transform Step */
							Matr[Ptr] = (Cosine[j] * Matr[Ptr] + Sine[j] * Matr[pPtr]);
							Matr[pPtr] = Aux;

						/* Update Pointers */
							++Ptr;
							++pPtr;
						}
					}
				}

			/* Shift All Diagonal Elements Back */
				for (j = 0; j <= i; ++j)
				{
					Diag[j] += Shift;
				}

			/* Convergence Check */
				SuperDiagNorm1 = fabs(ExDiag[i]);
				SuperDiagNorm2 = fabs(ExDiag[i-1]);

				Ratio = 1.0 / (SuperDiagNorm1 + SuperDiagNorm2 + Accu);

				if (SuperDiagNorm1 < SuperDiagNorm2)
				{
					Ratio *= SuperDiagNorm1;
					Flag = true;
				}
				else
				{
					Ratio *= SuperDiagNorm2;
					Flag = false;
				}

			/* Iteration Complete - Show Progress */
				cerr << ".";
			}

			if (Flag == true)
			{
			/* Output Eigenvalue */
				cerr << "[" << i << "]";

			/* Last Column Converged to Unit Vector */
				--i;
			}
			else
			{
			/* Split Off 2 x 2 - Matrix and Diagonalize */
				Aux = ExDiag[i];

			/* Matrix Already Diagonal? */
				if (fabs(Aux) > Accu * (fabs(Diag[i-1]) + fabs(Diag[i])))
				{
				/* No, Perform Jacobi Rotation [Stoer/Bulirsch Ch. 6.5.2]: */
				/* Angles */
					theta = (Diag[i-1] - Diag[i]) / (2.0 * Aux);
					t     = 1.0 / (fabs(theta) + sqrt(1.0 + theta * theta));

					if (theta < 0)  (t = -t);

					c = 1.0 / sqrt(1.0 + t * t);
					s = t * c;

				/* Eigenvalues */
					Aux *= t;

					Diag[i-1] += Aux;
					Diag[i]   -= Aux;

				/* Perform Rotation in Unitary Transformation Matrix (If Required) */
					if (EigenvaluesOnly == false)
					{
					/* Pointers in Matrix */
						long Ptr  = i * MatrixDim;
						long mPtr = Ptr - MatrixDim;

						for (k = 0; k < MatrixDim; ++k)
						{
						/* Temporary Storage */
							Aux = c * Matr[Ptr] - s * Matr[mPtr];

							Matr[mPtr] = c * Matr[mPtr] + s * Matr[Ptr];
							Matr[Ptr]  = Aux;

						/* Update Pointers */
							++Ptr;
							++mPtr;
						}
					}
				}

			/* Output Eigenvalues */
				cerr << "[" << i << "," << i-1 << "]";

			/* Both Last Columns Converged to Unit Vector */
				i -= 2;
			}
		}

	/* Finish Progress/Control Output */
	    cerr << " ... done.\n";

	/* Free Temporary Element Storage */
		delete[] Cosine;
		delete[] Sine;
		delete[] OffDiag;

		return;
	}


/* *** MATHEMATICAL ROUTINES (HERMITIAN PROBLEMS) *** */

/* *** Householder Reduction to Tridiagonal Form (Hermitian Matrices)  */
/* *** Input:  Address of Array Containing Hermitian Matrix            */
/*             Addresses of Vector Arrays for Diagonal and             */
/*             Superdiagonal Elements                                  */
/*             (types: complex<double> and double, respectively)       */
/* *** Output: Diagonal and Superdiagonal Elements                     */
/*             Right-Hand Unitary Transformation Matrix (if desired)   */
/*             (replaces hermitian matrix)                             */
/* *** (see Stoer/Bulirsch, Ch. 6.5.1)                                 */
/*                                                                     */
/* *** Calling Convention:                                             */
/*     HouseholderHerm(&Matrix[0], &Diagonal[0], &SuperDiagonal[0]);   */
/*                                                                     */
/* *** Global Variables Required:                                      */
/*     MatrixDim --- Dimension of Input Matrix/Vectors                 */
/*     EigenvaluesOnly --- Omit Calculation of Unitary Transform       */
/* *** Required Function Calls:                                        */
/*     inline long Element(long Row, long Column) ---				   */
/*     Position of Matrix Element (Row,Column) in Matrix Arrays        */

	void HouseholderHerm(complex<double>*Matr, double *Diag, complex<double> *SupDiag)
	{
		int i,j,k;
		double Sum,Aux;
		complex<double> Phase;
		complex<double> Scalar;
		long iOffset,jOffset,kOffset;

	/* *** Perform Householder Transformations *** */
		cerr << "Householder tridiagonalization ";

		for (i = MatrixDim - 1; i > 1; --i)
		{
		/* Offset */
			iOffset = i * MatrixDim;

		/* Extract Diagonal Element */
			Diag[i] = real(Matr[Element(i,i)]);

		/* Calculate Norm of Partial Row/Column; "Hermitize" Matrix
		   (dispose of numerical deviations) */
			Sum = 0.0;
			for (k = 0; k < i; ++k)
			{
				Matr[iOffset + k] = conj(Matr[k * MatrixDim + i]);
				Sum += norm(Matr[iOffset + k]);

			}

		/* No Action Required If Already Empty */
			if (Sum == 0.0)
			{
				SupDiag[i] = Matr[Element(i-1, i)];
				Matr[Element(i, i)] = complex<double>(0.0, 0.0);
			}
			else
			{
			/* Determine Phase Factor */
				Phase = complex<double>(1.0, 0.0);
				Aux = sqrt(norm(Matr[Element(i-1, i)]));

				if (Aux > 0.0)
				{
					Phase = Matr[Element(i-1, i)] / Aux;
				}

			/* Superdiagonal Element */
				SupDiag[i] = - sqrt(Sum) * Phase;

			/* Partial Vector u = Matr[i] - SupDiag[i] (stored in Matrix) */
				Matr[Element(i-1, i)] -= SupDiag[i];
				Matr[Element(i, i-1)] -= conj(SupDiag[i]);

			/* Calculate Inverted (one-half) Norm of u and Store in Diag Part of Matrix */
				Aux = 1.0 / (Sum + sqrt(Sum) * Aux);
				Matr[Element(i, i)] = complex<double>(Aux, 0.0);

			/* Partial Vector p = Matr * u / Norm, Stored in Unused Part of SupDiag[i] */
				for (k = 0; k < i; ++k)
				{
				/* Offset */
					kOffset = k * MatrixDim;

					SupDiag[k] = 0.0;
					for (j = 0; j < i; ++j)
					{
						SupDiag[k] += Matr[kOffset + j] * Matr[j * MatrixDim + i];
					}
					SupDiag[k] *= Aux;
				}

			/* Scalar s = u^+ * p / Norm */
				Scalar = complex<double>(0.0,0.0);

				for (k = 0; k < i; ++k)
				{
					Scalar += Matr[iOffset + k] * SupDiag[k];
				}
				Scalar *= (0.5 * Aux);

			/* Vector q = p - s * u, in SupDiag[i] */

				for (k = 0; k < i; ++k)
				{
					SupDiag[k] -= Scalar * Matr[k * MatrixDim + i];
				}

			/* Householder Transformation on Partial Matrix */
				for (k = 0; k < i; ++k)
				{
				/* Offset */
					kOffset = k * MatrixDim;

					for (j = 0; j < i; ++j)
					{
					/* Offset */
						jOffset = j * MatrixDim;

						Matr[jOffset + k] -= (Matr[jOffset + i] * conj(SupDiag[k])
											   + Matr[iOffset + k] * SupDiag[j]);
					}
				}
			}
		/* Display Progress */
			cerr << ".";
		}

		cerr << " done.\n";

	/* Readout Leftover 2 x 2 Matrix */
		Diag[0] = real(Matr[Element(0,0)]);
		SupDiag[0] = complex<double>(0.0,0.0);

	/* Take Care of 1 x 1 - "Matrices" */
		if (MatrixDim > 1)
		{
			Diag[1] = real(Matr[Element(1,1)]);
			SupDiag[1] = Matr[Element(0,1)];
		}

	/* *** ASSEMBLE TRANSFORMATION MATRIX *** */

	/* Transformation Only If Desired */
		if (EigenvaluesOnly == false)
		{
			cerr << "Unitary transformation ";

		/* Step 1:  Initialize Matrix */
			Matr[Element(0,0)] = complex<double>(1.0,0.0);

		/* Take Care of 1 x 1 - "Matrices" */
			if (MatrixDim > 1)
			{
				Matr[Element(1,0)] = complex<double>(0.0,0.0);
				Matr[Element(0,1)] = complex<double>(0.0,0.0);
				Matr[Element(1,1)] = complex<double>(1.0,0.0);
			}

		/* Step 2:  Recursive Multiplication */
			for (i = 2; i < MatrixDim; ++i)
			{
			/* Offset */
				iOffset = i * MatrixDim;

			/* Readout Inverse Norm */
				Aux = real(Matr[Element(i,i)]);

			/* Loop Through Rows */
				for (j = 0; j < i; ++j)
				{
				/* Offset */
					jOffset = j * MatrixDim;

					Scalar = complex<double>(0.0,0.0);

				/* Loop Through Columns */
					for (k = 0; k < i; ++k)
					{
						Scalar += Matr[jOffset + k] * Matr[k * MatrixDim + i];
					}
					Scalar *= Aux;

					for (k = 0; k < i; ++k)
					{
						Matr[jOffset + k] -= Scalar * Matr[iOffset + k];
					}

				}

			/* Clean Matrix Row And Column */
				for (j = 0; j < i; ++j)
				{
					Matr[iOffset + j]       = complex<double>(0.0,0.0);
					Matr[j * MatrixDim + i] = complex<double>(0.0,0.0);
				}

				Matr[Element(i,i)] = complex<double>(1.0,0.0);

			/* Display Progress */
				cerr << ".";
			}

		/* Finish up */
			cerr << " done.\n";
		}

		return;
	}


/* *** Diagonalization of Tridiagonal Hermitian Matrices               */
/*     QR Algorithm with Explicit Shift                                */
/* *** Input:  Address of Array Containing Unitary Transformation      */
/*             from Previous Householder Tridiagonalization            */
/*             (or a unit matrix, if no tridiagonalization required)   */
/*             Addresses of Vector Arrays for Diagonal and             */
/*             Superdiagonal Elements                                  */
/*             (types complex<double> and double, respectively)        */
/* *** Output: Eigenvalues (replace diagonal elements)                 */
/*             Right-Hand Unitary Transformation Matrix                */
/*             (conjugate eigenvectors are stored in rows)             */
/* *** (see Stoer/Bulirsch, Ch. 6.6.4, 6.6.5)                          */
/*                                                                     */
/* *** Calling Convention:                                             */
/*     QRHerm(&Matrix[0], &Diagonal[0], &SuperDiagonal[0]);            */
/*                                                                     */
/* *** Global Variables Required:                                      */
/*     MatrixDim --- Dimension of Input Matrix/Vectors                 */
/* *** Required Function Calls:                                        */
/*     inline long Element(long Row, long Column) ---				   */
/*     Position of Matrix Element (Row,Column) in Matrix Arrays        */

	void QRHerm(complex<double> *Matr, double *Diag, complex<double> *SupDiag)
	{
		int i,j,k,Count;
		double Aux,Shift,SquareRoot;
		double theta,t,c,s;
		double OldCos,SuperDiagNorm;
		double SuperDiagNorm1,SuperDiagNorm2,Ratio;
		complex<double> AuxC1,AuxC2,ph;
		bool Flag;

	/* Temporary Element Storage Allocation */
		double *Cosine  = new double[MatrixDim];
		double *Sine    = new double[MatrixDim];
		double *OffDiag = new double[MatrixDim];

	/* Maximum Number of Iterations */
		int MaxIter = 30;

	/* Accuracy Goal for Off-Diagonal Elements */
		double Accu = 1e-16;
		double AccuSq = Accu * Accu;

	/* Element Counter */
		i = MatrixDim - 1;

	/* Set "Surplus" Element */
		SupDiag[0] = complex<double>(0.0,0.0);

	/* Start Message */
		cerr << "QR Diagonalization ";

	/* Successive Diagonalization of Lower Right Elements */
		while (i > 0)
		{
		/* Test Whether Diagonalization is Necessary */
			SuperDiagNorm1 = norm(SupDiag[i]);
			SuperDiagNorm2 = norm(SupDiag[i-1]);

			Ratio = 1.0 / (SuperDiagNorm1 + SuperDiagNorm2 + AccuSq);

			if (SuperDiagNorm1 < SuperDiagNorm2)
			{
				Ratio *= SuperDiagNorm1;
				Flag = true;
			}
			else
			{
				Ratio *= SuperDiagNorm2;
				Flag = false;
			}

			Count = 0;

			while ((i>1) && (Ratio > AccuSq))
			{
			/* Iteration Counter and Error Check */
				++Count;
				if (Count > MaxIter)
				{
					cout << "ERROR in routine QR():  No convergence \n\n";
					exit(0);
				}

			/* Guess for Explicit Shift (Stoer/Bulirsch 6.6.5.7b) */
				Aux = .5 * (Diag[i] - Diag[i-1]);
				Shift = .5 * (Diag[i] + Diag[i-1]);
				SquareRoot = sqrt(Aux * Aux + SuperDiagNorm1);

				if (Aux > 0)
				{
					Shift += SquareRoot;
				}
				else
				{
					Shift -= SquareRoot;
				}

			/* Shift All Diagonal Elements */
				for (j = 0; j <= i; ++j)
				{
					Diag[j] -= Shift;
				}

			/* Sequence of Givens Rotations to Annihilate Lower Subdiagonal */
				OldCos = 1.0;

				for (j = 0; j < i; ++j)
				{
					SuperDiagNorm = sqrt(norm(SupDiag[j+1]));

					if (SuperDiagNorm > Accu * fabs(Diag[j]))
					{
					/* Givens Rotation */
						Aux = 1.0 / sqrt(SuperDiagNorm * SuperDiagNorm
							+ Diag[j] * Diag[j]);

					/* Parameters to Store */
						Cosine[j]  = Diag[j] * Aux;
						Sine[j]    = SuperDiagNorm * Aux;
						OffDiag[j] = Cosine[j] * OldCos * SuperDiagNorm
						             + Sine[j] * Diag[j+1];

					/* Store Sine x Phase Temporarily in Superdiagonal Element */
						SupDiag[j+1] *= Aux;

					/* Actual Rotation (off-diagonal elements not required) */
						Diag[j]    = Cosine[j] * Diag[j] + Sine[j] * SuperDiagNorm;
						Diag[j+1]  = Cosine[j] * Diag[j+1]
						             - Sine[j] * OldCos * SuperDiagNorm;
					}
					else
					{
					/* No Rotation Required, Store Identity */
						Cosine[j]    = 1.0;
						Sine[j]      = 0.0;
						OffDiag[j]   = 0.0;
						SupDiag[j+1] = complex<double>(0.0,0.0);
					}

					OldCos = Cosine[j];
				}

			/* Pointers Into Unitary Matrix */
				long Ptr  = 0;
				long pPtr = MatrixDim;

			/* Sequence of Conjugate Givens Rotations to Complete Unitary Transform */
				for (j = 0; j < i; ++j)
				{
				/* Perform Rotation in Unitary Transformation Matrix (If Required) */
					if (EigenvaluesOnly == false)
					{
						for (k = 0; k < MatrixDim; ++k)
						{
						/* Temporary Complex Storage */
							AuxC2 = Cosine[j] * Matr[pPtr]
							        - conj(SupDiag[j+1]) * Matr[Ptr];

							Matr[Ptr] = Cosine[j] * Matr[Ptr]
							            + SupDiag[j+1] * Matr[pPtr];
							Matr[pPtr] = AuxC2;

						/* Update Pointers */
							++Ptr;
							++pPtr;
						}
					}

				/* Givens Rotation */
					Diag[j]       = Cosine[j] * Diag[j] + Sine[j] * OffDiag[j];
					SupDiag[j+1] *= Diag[j+1];
					Diag[j+1]    *= Cosine[j];
				}

			/* Shift All Diagonal Elements Back */
				for (j = 0; j <= i; ++j)
				{
					Diag[j] += Shift;
				}

			/* Convergence Check */
				SuperDiagNorm1 = norm(SupDiag[i]);
				SuperDiagNorm2 = norm(SupDiag[i-1]);

				Ratio = 1.0 / (SuperDiagNorm1 + SuperDiagNorm2 + AccuSq);

				if (SuperDiagNorm1 < SuperDiagNorm2)
				{
					Ratio *= SuperDiagNorm1;
					Flag = true;
				}
				else
				{
					Ratio *= SuperDiagNorm2;
					Flag = false;
				}

			/* Iteration Complete - Show Progress */
				cerr << ".";
			}

			if (Flag == true)
			{
			/* Output Eigenvalue */
				cerr << "[" << i << "]";

			/* Last Column Converged to Unit Vector */
				--i;
			}
			else
			{
			/* Split Off 2 x 2 - Matrix and Diagonalize */
				Aux = sqrt(SuperDiagNorm1);

			/* Matrix Already Diagonal? */
				if (Aux > Accu * (fabs(Diag[i-1]) + fabs(Diag[i])))
				{
				/* No, Perform Jacobi Rotation [Stoer/Bulirsch Ch. 6.5.2]: */
				/* Phase */
					ph = SupDiag[i] / Aux;

				/* Angles */
					theta = (Diag[i-1] - Diag[i]) / (2.0 * Aux);
					t     = 1.0 / (fabs(theta) + sqrt(1.0 + theta * theta));

					if (theta < 0)  (t = -t);

					c = 1.0 / sqrt(1.0 + t * t);
					s = t * c;

				/* Eigenvalues */
					Aux *= t;

					Diag[i-1] += Aux;
					Diag[i]   -= Aux;

				/* Perform Rotation in Unitary Transformation Matrix (If Required) */
					if (EigenvaluesOnly == false)
					{
					/* Pointers in Matrix */
						long Ptr  = i * MatrixDim;
						long mPtr = Ptr - MatrixDim;

					/* Product of Sine and Phase */
						AuxC1 = s * ph;

						for (k = 0; k < MatrixDim; ++k)
						{
						/* Temporary Complex Storage */
							AuxC2 = c * Matr[Ptr] - conj(AuxC1) * Matr[mPtr];

							Matr[mPtr] = c * Matr[mPtr] + AuxC1 * Matr[Ptr];
							Matr[Ptr]  = AuxC2;

						/* Update Pointers */
							++Ptr;
							++mPtr;
						}
					}
				}

			/* Output Eigenvalues */
				cerr << "[" << i << "," << i-1 << "]";

			/* Both Last Columns Converged to Unit Vector */
				i -= 2;
			}
		}

	/* Finish Progress/Control Output */
	    cerr << " ... done.\n";

	/* Free Temporary Element Storage */
		delete[] Cosine;
		delete[] Sine;
		delete[] OffDiag;

		return;
	}

/* *** Sorting of Eigenvalues (Ascending Order)                        */
/* *** Input:  Address of Array Containing Eigenvalues                 */
/*             Address of Array of 'long' type                         */
/*             (for lookup table pointer storage)                      */
/* *** Output: Pointers to Eigenvalues:                                */
/*             EVPointer[0] Contains Index of Smallest Eigenvalue      */
/*             EVPointer[MatrixDim - 1] Contains Index of              */
/*             Largest Eigenvalue                                      */
/*                                                                     */
/* *** Calling Convention:                                             */
/*     EigenSort(&EVArray[0], &EVPointer[0]);                          */
/*                                                                     */
/* *** Global Variables Required:                                      */
/*     MatrixDim --- Dimension of Input Matrix/Vectors                 */

	void EigenSort(double *EVArray, long *EVPointer)
	{
		int i,j,Aux,Pos;
		double MinEV,MaxEV;

	/* Initialization*/
		MinEV = EVArray[0];

		for (i = 0; i < MatrixDim; ++i)
		{
			EVPointer[i] = i;
			if (EVArray[i] < MinEV)  MinEV = EVArray[i];
		}

	/* Outer Comparison Loop */
		for (i = MatrixDim; i > 1; --i)
		{
			MaxEV = MinEV;
			Pos = 0;

		/* Inner Comparison Loop */
			for (j = 0; j < i; ++j)
			{
				if (EVArray[EVPointer[j]] > MaxEV)
				{
					MaxEV = EVArray[EVPointer[j]];
					Pos   = j;
				}
			}

		/* Swap As Necessary */
			Aux           = EVPointer[Pos];
			EVPointer[Pos] = EVPointer[i-1];
			EVPointer[i-1] = Aux;
		}

		return;
	}

/* *** STRING OUTPUT FORMATTING *** */

/* Auxiliary Function:  Output Integer as String */
   string ConvertIntegerToString(int Number)
   {
   		string Text = "";
   		int Digit;
   		int Sign = 0;

   		if (Number < 0)
   		{
   			Sign = 1;
   			Number = -Number;
   		}

   		if (Number == 0)
   		{
   			Text.append("0");
   		}
   		else
   		{
   			while (Number > 0)
   			{
   				Digit = (Number % 10);
   				Number /= 10;

   				Text.insert((string::size_type)0, (int)1, (char)(Digit + 48));
   			}
   		}

   		if (Sign == 1)  Text.insert((string::size_type)0, 1, '-');

   		return Text;
   	}

/* Auxiliary Function:  Format Numerical Part */
	string NumCoefficient(int Value)
	{
		string NStr = "";

		if (Value != 0)
		{
		/* Symbolic String - (1) Sign: */
			if (Value > 0)  NStr.append("+");
			else            NStr.append("-");

		/* Symbolic String - (2) Coefficient: */
			if (Value < 0)  (Value = -Value);

			if (Value != 1)
			{
				NStr.append(ConvertIntegerToString(Value));
			}
		}

		return NStr;
	}

/* Format a Rate Matrix Element For Output */
	string CoefficientString(char A, char B, char C, char D)
	{
		string CStr = "";
		string Aux;

	/* Add Single Coefficient Strings */
		if (A != 0)  (CStr += NumCoefficient((int)A) + "A");
		if (B != 0)  (CStr += NumCoefficient((int)B) + "B");
		if (C != 0)  (CStr += NumCoefficient((int)C) + "C");
		if (D != 0)  (CStr += NumCoefficient((int)D) + "D");

	/* Post-Formatting */
		int Length = CStr.size();

		if (Length == 0)
		{
		/* Zero Coefficient */
			CStr = "0";
			++Length;
		}
		else
		{
		/* Remove Leading "+" Signs */
			if (Aux.assign(CStr, 0, 1) == "+")
			{
				CStr.assign(CStr, 1, Length - 1);
				--Length;
			}
		}

	/* Padding With White Space */
		int RightSpace = (18 - Length) / 2;
		int LeftSpace  = 18 - Length - RightSpace;

		CStr.insert((string::size_type)0, LeftSpace, ' ');
		CStr.append(RightSpace, ' ');

		return CStr;
	}


/* *** EVALUATION OF COMMAND LINE OPTIONS *** */

/* User Help Screen */
	inline void usage(int exit_value=0)
	{
		cerr << " Usage:  DIFF pattern output_file [option_keys] \n\n"
			 << " Available options:\n\n"
			 << " /? .............. Open this help screen \n"
			 << " /[ .............. Select left eigenvectors of rate matrix \n"
			 << " /] .............. Select right eigenvectors of rate matrix \n"
			 << " /#=Momentum ..... Restrict calculation to momentum subspace # \n"
			 << " /1 .............. Output average for single sites (default) \n"
			 << " /2 .............. Output averages for pairs of sites \n"
			 << " /A=Rate ......... Rate for type - A jumps (1.00) \n"
			 << " /B=Rate ......... Rate for type - B jumps (1.00) \n"
			 << " /c .............. Check accuracy of diagonalization \n"
			 << " /C=Rate ......... Rate for type - C jumps (1.00) \n"
			 << " /d=Digits ....... Output precision in digits (2...16) [6] \n"
			 << " /D=Rate ......... Rate for type - D jumps (1.00) \n"
			 << " /e .............. Show ordered eigenvalues \n"
			 << " /E .............. Show associated eigenvectors \n"
			 << " /h .............. Open this help screen \n"
			 << " /l=filename ..... Load transformation matrix from disk \n"
			 << " /L ........ ..... Use logarithmic time scale \n"
			 << " /n ........ ..... No temporal evolution of averages \n"
			 << " /o ........ ..... Show coefficient rate matrix \n"
			 << " /p .............. Show all primitive patterns \n"
			 << " /P=pattern ...... Output average for specified pattern(s) \n"
			 << " /q .............. Output equilibrium average \n"
			 << " /Q .............. Calculate projection on <q> \n"
			 << " /s=filename ..... Save transformation matrix to disk \n"
			 << " /S=steps ........ Number of steps for evolution [100] \n"
			 << " /t=Time ......... Start of evolution [0.00] \n"
			 << " /T=Time ......... Stop of evolution [10.00] \n"
			 << " /u .............. No unitary transformation \n"
			 << " /v .............. Output deviation from equilibrium average \n"
 			 << " /x .............. Use mantissa-exponent float format \n"
			 << " /y .............. Post-symmetrize eigenvectors \n"
			 << " /z .............. Show eigenvector weight in initial state \n\n";
		exit(exit_value);
	}

/* Error Handler For Illegal Options */
	void UnrecognizedKey(string Key)
	{
		cerr << "ERROR:  Unrecognized Option " << Key.c_str() << "\n\n";
		exit(1);
	}

/* Extraction of Numerical Values Accompanying Command Line Options */
	double ExtractValue(string Key)
	{
		double NumValue=0;
		string ValueString;

		if (Key.size() < 4) UnrecognizedKey(Key);
		else
		{
	/* Isolate Parameter */
			ValueString.assign(Key,3,Key.size() - 3);
			NumValue = atof(ValueString.c_str());
		}
		return NumValue;
	}

/* Extraction of String Values Accompanying Command Line Options */
	string ExtractString(string Key)
	{
		string ValueString;

		if (Key.size()< 4) UnrecognizedKey(Key);
		else
		{
	/* Isolate Parameter */
			ValueString.assign(Key,3,Key.size()-3 );
		}
		return ValueString;
	}

/* A Pattern Testing Routine */
	void TestPattern(string AtomPattern, bool IsIndefinite)
	{
	/* Length of Pattern */
		int Size = AtomPattern.size();
		string Aux;

		for (int i=0; i < Size; ++i)
		{
			Aux.assign(AtomPattern,i,1);

		/* "o" Denotes Atom, "." Denotes Hole, "x" Denotes Undefined (Either) Type */
			if ((Aux != ".") && (Aux != "o") && (Aux != "x"))
			{
			/* Unrecognized Symbol */
				ErrorMessage("Illegal Symbol in Pattern");
			}

		/* Symbol "x" Is Allowed Only in Indefinite Mode */
			if ((IsIndefinite == false) && (Aux == "x"))
			{
			/* Unrecognized Symbol */
				ErrorMessage("Illegal Symbol in Pattern");
			}
		}
	}


/* *** MAIN PROGRAM ************************************************************** */

int main(int argc, char *argv[])
{
/* Opening Message */
	cerr << "\n"
		 << "DIFFUSION.c++ - Diffusion on a Circle - Canonical Ensemble\n"
		 << "(Version " << VersionSpec << ", written " << VersionDate << ")\n"
		 << "Author:  Christian Bracher\n\n";


/* *** SOME VARIABLES *** */

/* Some Standard Variable Names */
	long i,j,l,nu;
	double Aux,Sum;
	complex<double> AuxC;
	Pattern Current;

/* Auxiliary Field:  Powers of 2 */
	exp2pow = new unsigned long[32];
	exp2pow[0] = 1;
	for (i = 1; i < 32; ++i)
	{
		exp2pow[i] = exp2pow[i-1] * 2;
	}

/* Auxiliary Field:  Averaging Pattern Storage */
	AveragePattern = new string[MaxAvgPatNum];
	AveragePatternNumber = 0;


/* *** COMMAND LINE INTERPRETER *** */

	/* Get Filename for Input and Output */
		if (argc < 3)
		{
			cerr << "ERROR:  Input pattern and/or output filename missing.\n\n";
			usage();
		}

		char *InputChar = argv[1];
		InitialState = InputChar;

		char *OutputChar = argv[2];
		OutputFilename = OutputChar;

	/* Evaluate Keys */
		string OptionText;
		string AuxString;

		for (i=3; i<argc; ++i)
		{
			char *pchar = argv[i];
			OptionText = pchar;

			if (pchar[0] != '/') UnrecognizedKey(OptionText);

			switch (pchar[1])
			{
			case '?':
			/* Show Help Screen */
				if (OptionText != "/?")
					UnrecognizedKey(OptionText);
				usage();
				break;
			case '[':
			/* Select Left Eigenvectors of Unsymmetrized Matrix */
				if (OptionText != "/[")
					UnrecognizedKey(OptionText);
					ShowLeftEV  = true;
					ShowRightEV = false;
				break;
			case ']':
			/* Select Right Eigenvectors of Unsymmetrized Matrix */
				if (OptionText != "/]")
					UnrecognizedKey(OptionText);
					ShowLeftEV  = false;
					ShowRightEV = true;
				break;
			case '#':
			/* Select Single Momentum Subspace */
				QSubspace = (int)ExtractValue(OptionText);
				SingleQSubspace = true;
				Evolution = false;
				break;
			case '1':
			/* One-Site Averages */
				if (OptionText != "/1")
					UnrecognizedKey(OptionText);
				OneAtom = true;
				TwoAtom = false;
				CustomPattern = false;
				break;
			case '2':
			/* One-Site Averages */
				if (OptionText != "/2")
					UnrecognizedKey(OptionText);
				OneAtom = false;
				TwoAtom = true;
				CustomPattern = false;
				break;
			case 'A':
			/* Rate for Jumps of Type A */
				RateA = ExtractValue(OptionText);
				if (RateA <= 0)
					UnrecognizedKey(OptionText);
				break;
			case 'B':
			/* Rate for Jumps of Type B */
				RateB = ExtractValue(OptionText);
				if (RateB <= 0)
					UnrecognizedKey(OptionText);
				break;
			case 'c':
			/* Check Accuracy of Diagonalization */
				if (OptionText != "/c")
					UnrecognizedKey(OptionText);
				CheckAccuracy = true;
				break;
			case 'C':
			/* Rate for Jumps of Type C */
				RateC = ExtractValue(OptionText);
				if (RateC <= 0)
					UnrecognizedKey(OptionText);
				break;
			case 'd':
			/* Output Precision in Digits */
				OutputPrecision = (int)ExtractValue(OptionText);
				if (OutputPrecision < 2)
					UnrecognizedKey(OptionText);
				if (OutputPrecision > 16)
					OutputPrecision = 16;
				break;
			case 'D':
			/* Rate for Jumps of Type D */
				RateD = ExtractValue(OptionText);
				if (RateD <= 0)
					UnrecognizedKey(OptionText);
				break;
			case 'e':
			/* Show Eigenvalues */
				if (OptionText != "/e")
					UnrecognizedKey(OptionText);
				ShowEigenvalues = true;
				break;
			case 'E':
			/* Show Eigenvectors */
				if (OptionText != "/E")
					UnrecognizedKey(OptionText);
				ShowEigenvectors = true;
				break;
			case 'h':
			/* Open Help Screen */
				if ((OptionText != "/h") && (OptionText != "/help"))
					UnrecognizedKey(OptionText);
				usage();
				break;
			case 'l':
			/* Load Transformation Matrix From Disk */
				BlockFilename = ExtractString(OptionText);
				LoadBlockData = true;
				SaveBlockData = false;
				break;
			case 'L':
			/* Use Logarithmic Time Scale */
				if (OptionText != "/L")
					UnrecognizedKey(OptionText);
				LogScale = true;
				break;
			case 'n':
			/* Suppress Output of Temporal Evolution Data */
				if (OptionText != "/n")
					UnrecognizedKey(OptionText);
				Evolution = false;
				break;
			case 'o':
			/* Output Rate Coefficient Matrix */
				if (OptionText != "/o")
					UnrecognizedKey(OptionText);
				ShowRateMatrix = true;
				break;
			case 'p':
			/* Show All Primitive Patterns */
				if (OptionText != "/p")
					UnrecognizedKey(OptionText);
				ShowPrimitives = true;
				break;
			case 'P':
			/* Use Custom Pattern(s) For Averaging */
				AveragePattern[AveragePatternNumber] = ExtractString(OptionText);
				++AveragePatternNumber;
				OneAtom = false;
				TwoAtom = false;
				CustomPattern = true;
				break;
			case 'q':
			/* Show Equilibrium Averages */
				if (OptionText != "/q")
					UnrecognizedKey(OptionText);
				EquilibriumAverage = true;
				break;
			case 'Q':
			/* Show Contribution to One-Site Momentum Average <q> */
				if (OptionText != "/Q")
					UnrecognizedKey(OptionText);
				ShowQContribution = true;
				break;
			case 's':
			/* Save Transformation Matrix From Disk */
				BlockFilename = ExtractString(OptionText);
				LoadBlockData = false;
				SaveBlockData = true;
				break;
			case 'S':
			/* Number of Steps in Temporal Evolution */
				Steps = (long)ExtractValue(OptionText);
				if (Steps < 1)
					UnrecognizedKey(OptionText);
				break;
			case 't':
			/* Start Time for Temporal Evolution */
				StartTime = ExtractValue(OptionText);
				break;
			case 'T':
			/* Stop Time for Temporal Evolution */
				StopTime = ExtractValue(OptionText);
				break;
			case 'u':
			/* Do Not Determine Unitary Transform */
				if (OptionText != "/u")
					UnrecognizedKey(OptionText);
				EigenvaluesOnly = true;
				ShowEigenvalues = true;
				Evolution = false;
				break;
			case 'v':
			/* Output Deviation From Equilibrium Averages */
				if (OptionText != "/v")
					UnrecognizedKey(OptionText);
				ShowDeviation = true;
				break;
			case 'x':
			/* Use Mantissa-Exponent Float Format in Average Data */
				if (OptionText != "/x")
					UnrecognizedKey(OptionText);
				FixedDataFormat = false;
				break;
			case 'y':
			/* Post-Symmetrize Eigenvectors */
				if (OptionText != "/y")
					UnrecognizedKey(OptionText);
				SymmetrizeEigenvectors = true;
				break;
			case 'z':
			/* Output Weight of Eigenvectors in Initial State */
				if (OptionText != "/z")
					UnrecognizedKey(OptionText);
				ShowEVWeight = true;
				break;
			default:
				UnrecognizedKey(OptionText);
				usage();
			}
		}


/* *** OPEN INPUT/OUTPUT FILES *** */

/* Open Info Output File */
	InfoFilename = OutputFilename + ".INF";
	ofstream Info(InfoFilename.c_str());
	if (!Info)
		ErrorMessage("Could Not Open Information File");
	Info.precision(14);

/* Write Opening Message */
	Info << "DIFFUSION.c++ - Diffusion on a Circle - Canonical Ensemble\n"
		 << "(Version " << VersionSpec << ", written " << VersionDate << ")\n"
		 << "Author:  Christian Bracher\n\n";

/* Open Data Output File */
	DataFilename = OutputFilename + ".DAT";
	ofstream Data(DataFilename.c_str());
	if (!Data)
		ErrorMessage("Could Not Open Output Data File");

/* Data Output in Selected Mode */
	if (FixedDataFormat == true)
	{
	/* Fixed-Length Format */
		Data.setf(ios_base::fixed, ios_base::floatfield);
	}
	else
	{
	/* Scientific Format */
		Data.setf(ios_base::scientific, ios_base::floatfield);
	}

/* Accommodate Signs If Required */
	if (ShowDeviation == true)
	{
		Data.setf(ios_base::showpos);
	}

/* Data Output Precision */
	Data.precision(OutputPrecision);


/* *** TEST OPTION COMPATIBILITIES *** */

/* Omit Unitary Transform */
	if (EigenvaluesOnly == true)
	{
		if ((CheckAccuracy == true) ||
			(ShowEigenvectors == true) ||
			(ShowQContribution == true) ||
			(LoadBlockData == true) ||
			(SaveBlockData == true))
		{
			ErrorMessage("Options /u and /c, /E, /l, /Q, or /s incompatible");
		}
	}

/* Select Single Subspace */
	if (SingleQSubspace == true)
	{
		if ((LoadBlockData == true) || (SaveBlockData == true))
		{
			ErrorMessage("Options /# and /l or /s incompatible");
		}
	}


/* *** FETCH AND TEST INITIAL STATE *** */

/* Test Initial State Pattern (a definite pattern) */
	TestPattern(InitialState, false);

/* Size of Initial Pattern */
	p = InitialState.size();

/* Permitted Range of Sites: 3...31 */
	if (p < 3)
		ErrorMessage("At least three sites required");
	if (p > 31)
		ErrorMessage("At most 31 sites permitted");

/* Is Number of Sites Prime? */
	if (IsPrime(p) == false)
		ErrorMessage("Number of sites must be prime");

/* Extract Pattern, Number of Atoms */
	Pattern InitState = InitialState;
	k = InitState.AtomNum();

/* Check for Valid Atom Number */
	if ((k == 0) || (k == p))
		ErrorMessage("No atoms (holes) present");


/* *** PREPARE OR TEST AVERAGING PATTERNS *** */

/* Create One-Atom Averaging Patterns (default) */
	if (OneAtom == true)
	{
		for (i=0; i<p; ++i)
		{
		/* Single Atom Pattern */
			AveragePattern[i] = "";
			AveragePattern[i].append(i, 'x');
			AveragePattern[i].append(1, 'o');
			AveragePattern[i].append(p-i-1, 'x');
		}

		AveragePatternNumber = p;
	}

/* Create Two-Atom Averaging Patterns, If Desired */
	if (TwoAtom == true)
	{
	/* Offset */
		AveragePatternNumber = 0;

		for (i=0; i < p-1; ++i)
		{
			for (j=0; j < p-1-i; ++j)
			{
			/* First Atom Position */
				AveragePattern[AveragePatternNumber] = "";
				AveragePattern[AveragePatternNumber].append(i, 'x');
				AveragePattern[AveragePatternNumber].append(1, 'o');

			/* Second Atom Position */
				AveragePattern[AveragePatternNumber].append(j, 'x');
				AveragePattern[AveragePatternNumber].append(1, 'o');

			/* Complete Pattern */
				AveragePattern[AveragePatternNumber].append(p - i - j - 2, 'x');

				++AveragePatternNumber;
			}
		}
	}

/* Test Custom Average State(s), If Necessary */
	if (CustomPattern == true)
	{
		for (i=0; i < AveragePatternNumber; ++i)
		{
		/* Test Pattern (an indefinite pattern) */
			TestPattern(AveragePattern[i], true);

		/* Test Size Compatibility */
			if (AveragePattern[i].size() != p)
				ErrorMessage("Size of averaging pattern mismatch");
		}
	}

/* *** CHECK TEMPORAL LIMITS *** */

/* Test Limits, If Necessary */
	if (Evolution == true)
	{
	/* Check Chronological Order */
		if (StartTime >= StopTime)
			ErrorMessage("Start must occur before stop in evolution");

	/* Check For Forward Evolution */
		if (StartTime < 0.0)
			ErrorMessage("Negative start time");

	/* Check Validity of LogScale Option */
		if ((LogScale == true) && (StartTime == 0.0))
			ErrorMessage("Logarithmic scale requires positive start time");
	}


/* *** CHECK BLOCK DATA FILE IF REQUIRED *** */

/* Open Block Data File For Reading, If Necessary */
	if (LoadBlockData == true)
	{
	/* Append Suffix ".BLK" */
		BlockFilename.append(".BLK");

	/* Check Validity of Transformation Matrix Filename */
		ifstream BlockLoad(BlockFilename.c_str());
		if (!BlockLoad)
			ErrorMessage("Could Not Open Block Data File");

	/* Input Buffers */
		long LongInputBuffer;
		double DoubleInputBuffer;

	/* Check for Validity of Parameter Set */
		bool SameParameterSet = true;

		BlockLoad.read((char *)&LongInputBuffer, sizeof p);
		if (LongInputBuffer != p)  SameParameterSet = false;
		BlockLoad.read((char *)&LongInputBuffer, sizeof k);
		if (LongInputBuffer != k)  SameParameterSet = false;

		BlockLoad.read((char *)&DoubleInputBuffer, sizeof RateA);
		if (DoubleInputBuffer != RateA)  SameParameterSet = false;
		BlockLoad.read((char *)&DoubleInputBuffer, sizeof RateB);
		if (DoubleInputBuffer != RateB)  SameParameterSet = false;
		BlockLoad.read((char *)&DoubleInputBuffer, sizeof RateC);
		if (DoubleInputBuffer != RateC)  SameParameterSet = false;
		BlockLoad.read((char *)&DoubleInputBuffer, sizeof RateD);
		if (DoubleInputBuffer != RateD)  SameParameterSet = false;

	/* Abort, If Supplied Data Deviates From Stored Data */
		if (SameParameterSet == false)
		{
		/* Failure - Parameters At Variance */
			ErrorMessage("Incompatible Parameter Sets");
		}

		BlockLoad.close();
	}

/* Open Block Data File For Writing, If Necessary */
	if (SaveBlockData == true)
	{
	/* Append Suffix ".BLK" */
		BlockFilename.append(".BLK");

	/* Check Validity of Transformation Matrix Filename */
		ofstream BlockSave(BlockFilename.c_str());
		if (!BlockSave)
			ErrorMessage("Could Not Open Block Data File");
		BlockSave.close();
	}


/* *** START PROGRAM *** */

/* Display Problem Under Consideration */
	cerr << "Evolution of the state " << InitState.Graphics()
		 << "  (" << k << " atoms on " << p << " sites)\n\n";

/* Write Parameter Set Into Information File */
	Info << "Evolution of the state " << InitState.Graphics()
		 << "  (" << k << " atoms on " << p << " sites)\n\n"
		 << "Rate for jumps of type A: " << RateA << "\n"
		 << "Rate for jumps of type B: " << RateB << "\n"
		 << "Rate for jumps of type C: " << RateC << "\n"
		 << "Rate for jumps of type D: " << RateD << "\n\n";

/* Calculate Complex Roots of Unity */
	UnityRoot = new complex<double>[p+1];

	for (i = 0; i <= p; ++i)
	{
		UnityRoot[i] = polar(1.0, 2.0 * i * Pi / p);
	}


/* *** SELECT PRIMITIVE PATTERNS *** */

/* Calculate Number of Primitive Patterns */
	double PrimNumAux = 1.0;

	for (i = p-k+1; i < p; ++i)
	{
		PrimNumAux *= i;
	}
	for (i = 2; i <= k; ++i)
	{
		PrimNumAux /= i;
	}

	PrimNum = (long)(PrimNumAux + 0.5);

/* Check Bounds */
	if (PrimNum > MaxPrimNum)
		ErrorMessage("Maximum number of patterns exceeded");

/* Set Matrix Dimension */
	MatrixDim = PrimNum;

/* Select Primitive Patterns */
	cerr << "Selecting " << PrimNum << " primitive patterns ... ";

/* Allocate Memory */
	Primitive = new Pattern[PrimNum];

/* Extract Primitive Patterns */
/* (Advanced algorithm:  Find ordered sequence of k-atom patterns using bit shifts) */

/* Primitive Pattern Counter */
	j = 0;

/* Initially, Set a Block of k Atoms to the Left */
	Current = exp2pow[k] - 1;

	do
	{
	/* Verify If Primitive */
		if (Current.PatternSum() == 0)
		{
			Primitive[j] = Current;
			++j;
		}

	/* Pick First Suitable Atom Num For Shift */
		int Num = 1;
		while (Current.IncrementSiteBlocked(Num))  ++Num;

	/* Extract Position of Atom */
		int Pos = Current.Element(Num);

    /* Shift this Atom to the Right (discard type of jump information) */
		int Nul = Current.Increment(Num);

	/* Clear Positions to the Left of this Atom */
		Current.Code &= (~(exp2pow[Pos] - 1));

	/* Set a Block of (Num - 1) Atoms to the Extreme Left */
		Current.Code |= (exp2pow[Num-1] - 1);
	}
	while (j < PrimNum);

/* Setup Storage For Mirror Property */
	MirrorImage = new int[PrimNum];

/* Establish Mirror Image Relationships */
	PalinNum = 0;

	for (i=0; i < PrimNum; ++i)
	{
	/* Form Mirror Image */
		Current = Primitive[i];
		Current.Mirror();

	/* Find Image in Pattern List */
		MirrorImage[i] = PatternPosition(Current);

	/* Count Palindromic Patterns */
		if (MirrorImage[i] == i)  ++PalinNum;
	}

	cerr << "done.\n";

/* Establish Primitive Pattern, Shift For Initial Configuration */
	Pattern InitPrimitive = InitialState;
	int  Shift = InitPrimitive.Primitive();
	long State = PatternPosition(InitPrimitive);

/* Output Primitive Patterns, If Desired */
	if (ShowPrimitives == true)
	{
		Info << PrimNum << " primitive patterns found, including "
			  << PalinNum << " palindromic patterns:\n"
		     << "(mirror image in brackets, palindromic patterns marked by asterisk *)"
		     << "\n\n";

		for (i = 0; i < PrimNum; ++i)
		{
			Info << i << " \t--- " << Primitive[i].Graphics() << "  [";

		/* Mark Palindromic Patterns */
			if (MirrorImage[i] == i)
			{
				Info << "*]\n";
			}
			else
			{
				Info << MirrorImage[i] << "]\n";
			}
		}

		Info << "\n";

	/* Indicate Initial Configuration */
		Info << "(Initial Configuration [# of primitive|shift]: ["
			  << State << "|" << Shift << "] )\n\n";
	}


/* *** THE EQUILIBRIUM EIGENVECTOR *** */

/* Calculate and Normalize Equilibrium Eigenvector */
	cerr << "Determine equilibrium eigenvector ... ";

	EqEV = new double[PrimNum];

	Sum = 0;
	for (i=0; i < PrimNum; ++i)
	{
		EqEV[i] = pow(RateB / RateC, Primitive[i].CollapsingNumber());
		Sum += EqEV[i];
	}
	Sum = 1.0 / (p * Sum);

	for (i=0; i < PrimNum; ++i)
	{
		EqEV[i] *= Sum;
	}

	cerr << "done.\n\n";


/* *** THE RATE COEFFICIENT MATRIX *** */

/* Reserve Space for Decay Coefficient Matrices */
	Diagonal = new DecayCoefficients[PrimNum];
	Forward  = new DecayCoefficients[PrimNum * PrimNum];
	Backward = new DecayCoefficients[PrimNum * PrimNum];

/* Verify Successful Allocation of Memory */
	if ((Forward == 0) || (Backward == 0))
		ErrorMessage("Insufficient Memory");

/* Establish Rate Coeffient Matrix */
	cerr << "Establishing decay coefficient matrix ... ";

	for (i=0; i < PrimNum; ++i)
	{
	/* Examine All Possible Increment and Decrement Shifts */
		for (j=1; j <= k; ++j)
		{
			Current = Primitive[i];
			if (Current.IncrementSiteBlocked(j) == false)
			{
			/* Increment Shift */
				int Type  = Current.Increment(j);
				int Dummy = Current.Primitive();
				long Prim = PatternPosition(Current);
				switch(Type)
				{
				case 0:
					++Diagonal[i].RateCoeffA;
					++Forward[Element(Prim,i)].RateCoeffA;
					break;
				case 1:
					++Diagonal[i].RateCoeffB;
					++Forward[Element(Prim,i)].RateCoeffB;
					break;
				case 2:
					++Diagonal[i].RateCoeffC;
					++Forward[Element(Prim,i)].RateCoeffC;
					break;
				case 3:
					++Diagonal[i].RateCoeffD;
					++Forward[Element(Prim,i)].RateCoeffD;
					break;
				}
			}

			Current = Primitive[i];
			if (Current.DecrementSiteBlocked(j) == false)
			{
			/* Decrement Shift */
				int Type  = Current.Decrement(j);
				int Dummy = Current.Primitive();
				long Prim = PatternPosition(Current);
				switch(Type)
				{
				case 0:
					++Diagonal[i].RateCoeffA;
					++Backward[Element(Prim,i)].RateCoeffA;
					break;
				case 1:
					++Diagonal[i].RateCoeffB;
					++Backward[Element(Prim,i)].RateCoeffB;
					break;
				case 2:
					++Diagonal[i].RateCoeffC;
					++Backward[Element(Prim,i)].RateCoeffC;
					break;
				case 3:
					++Diagonal[i].RateCoeffD;
					++Backward[Element(Prim,i)].RateCoeffD;
					break;
				}
			}
		}
	}

	cerr << "done.\n";

/* Output Rate Matrix, If Desired */
	if (ShowRateMatrix == true)
	{
	/* Matrix For Forward Jumps */
		Info << "Rate coefficents for forward jumps:\n\n";

		for (i=0; i < PrimNum; ++i)
		{
			for (j=0; j < PrimNum; ++j)
			{
				string Aux;
				Aux = CoefficientString(Forward[Element(i,j)].RateCoeffA,
										Forward[Element(i,j)].RateCoeffB,
										Forward[Element(i,j)].RateCoeffC,
										Forward[Element(i,j)].RateCoeffD);
				Info << Aux.c_str();
			}

			Info << "\n";
		}
		Info << "\n";

	/* Matrix For Backward Jumps */
		Info << "Rate coefficents for backward jumps:\n\n";

		for (i=0; i < PrimNum; ++i)
		{
			for (j=0; j < PrimNum; ++j)
			{
				string Aux;
				Aux = CoefficientString(Backward[Element(i,j)].RateCoeffA,
										Backward[Element(i,j)].RateCoeffB,
										Backward[Element(i,j)].RateCoeffC,
										Backward[Element(i,j)].RateCoeffD);
				Info << Aux.c_str();
			}

			Info << "\n";
		}
		Info << "\n";

	/* Diagonal (Decay) Matrix Elements */
		Info << "Diagonal (decay) rate coefficents:\n\n";

		for (i=0; i < PrimNum; ++i)
		{
			string Aux;
			Aux = CoefficientString(Diagonal[i].RateCoeffA,
									Diagonal[i].RateCoeffB,
									Diagonal[i].RateCoeffC,
									Diagonal[i].RateCoeffD);
			Info << Aux.c_str();
		}

		Info << "\n\n";
	}


/* *** THE TRANSFORMATION MATRIX *** */

/* Reserve Memory For Structures */
	cerr << "Reserving storage for transformation matrices ... ";

	double *Diag = new double[(p+1) * PrimNum / 2];
	double *Unitary;

/* Storage For Unitary Transformation Matrix Required? */
	if ((EigenvaluesOnly == false) && (SingleQSubspace == false))
	{
		Unitary = new double[(p+1) * PrimNum * PrimNum / 2];
	}
	else
	{
		Unitary = new double[PrimNum * PrimNum];
	}

/* Verify Successful Allocation of Memory */
	if ((Diag == 0) || (Unitary == 0))
	{
		cerr << "\n\n";
		ErrorMessage("Insufficient Memory");
	}

	cerr << "done.\n\n";

/* Obtaining the Transformation Data */
	if (LoadBlockData == true)
	{
	/* Load Block Data From Disk, If Desired & Possible */
		cerr << "Reading block data from disk ... ";

	/* Check Validity of Transformation Matrix File */
		ifstream BlockLoad(BlockFilename.c_str(), ios::binary);
		if (!BlockLoad)
			ErrorMessage("Could Not Open Block Data File");

	/* Ignore Parameter Data */
		BlockLoad.seekg(2 * sizeof(long) + 4 * sizeof(double));

	/* Load Eigenvalues */
		BlockLoad.read((char *)&Diag[0], (p+1) * PrimNum * sizeof(double) / 2);
	/* Load Unitary Matrix Data, If Required */
		if (EigenvaluesOnly == false)
			BlockLoad.read((char *)&Unitary[0],
			               (p+1) * PrimNum * PrimNum * sizeof(double) / 2);

	/* Cleanup */
		BlockLoad.close();

		cerr << "done.\n\n";
	}
	else
	{
	/* Calculate the Transformation Matrix From Scratch */

	/* *** THE ZERO MOMENTUM SUBSPACE *** */

	if ((SingleQSubspace == false) || ((QSubspace % p) == 0))
	{
		/* Create Zero Momentum Submatrix */
			cerr << "Creating submatrix for momentum q = 0 ... ";

		/* Calculate Rate Matrix */
			for (i=0; i < PrimNum; ++i)
			{
				for (j=0; j < PrimNum; ++j)
				{
					Unitary[Element(i,j)] =
						RateA * (Forward[Element(i,j)].RateCoeffA
						         + Backward[Element(i,j)].RateCoeffA) +
						RateB * (Forward[Element(i,j)].RateCoeffB
						         + Backward[Element(i,j)].RateCoeffB) +
						RateC * (Forward[Element(i,j)].RateCoeffC
						         + Backward[Element(i,j)].RateCoeffC) +
						RateD * (Forward[Element(i,j)].RateCoeffD
						         + Backward[Element(i,j)].RateCoeffD);
				}

				Unitary[Element(i,i)] -= (RateA * Diagonal[i].RateCoeffA
												+ RateB * Diagonal[i].RateCoeffB
												+ RateC * Diagonal[i].RateCoeffC
												+ RateD * Diagonal[i].RateCoeffD);
			}

		/* Symmetrization Procedure */
			for (i=0; i < PrimNum; ++i)
			{
				for (j=i+1; j < PrimNum; ++j)
				{
					Unitary[Element(i,j)] *= sqrt(EqEV[j] / EqEV[i]);
					Unitary[Element(j,i)] = Unitary[Element(i,j)];
				}
			}

			cerr << "done.\n";

		/* Make a Copy For Testing Purposes, If Required */
			double *SymmMatrCopy;

			if (CheckAccuracy == true)
			{
			/* Provide Storage Space */
				SymmMatrCopy = new double[PrimNum * PrimNum];

			/* Verify Successful Allocation of Memory */
				if (SymmMatrCopy == 0)  ErrorMessage("Insufficient Memory");

			/* Copy the Matrix */
				for (i=0; i < PrimNum; ++i)
				{
					for (j=0; j < PrimNum; ++j)
					{
						SymmMatrCopy[Element(i,j)] = Unitary[Element(i,j)];
					}
				}
			}

		/* Successive Tridiagonalization and Diagonalization Routines */
			cerr << "Diagonalizing submatrix for momentum q = 0: \n\n";

		/* Auxiliary Extradiagonal Elements Storage */
			double *ExDiag = new double[PrimNum];

			HouseholderSymm(&Unitary[0], &Diag[0], &ExDiag[0]);
			QRSymm(&Unitary[0], &Diag[0], &ExDiag[0]);

		/* Destroy Extradiagonal Element Vector */
			delete[] ExDiag;

		/* Operations On Unitary Transformation Matrix */
			if (EigenvaluesOnly == false)
			{

			/* Remove Random Sign of Equilibrium Eigenvector */
				for (i=0; i < MatrixDim; ++i)
				{
					if (fabs(Diag[i]) < 1e-12)
					{
						RemoveCommonSign(&Unitary[Element(i,0)]);
					}
				}

			/* (Anti-)Symmetrize Eigenvectors, If Desired */
				if (SymmetrizeEigenvectors == true)
				{
				/* Temporary Storage For Symmetrization Purposes */
					double *SymmVec = new double[PrimNum];
					double *AntiVec = new double[PrimNum];

				/* Symmetrization */
					for (i=0; i < PrimNum; ++i)
					{
					/* Determine Norm of (Anti-)Symmetric Parts */
						double SymmNorm = ProjectSymm(&Unitary[Element(i,0)], &SymmVec[0]);
						double AntiNorm = ProjectAnti(&Unitary[Element(i,0)], &AntiVec[0]);

						if (SymmNorm > AntiNorm)
						{
						/* Dominant Symmetric Part:  Symmetrize Eigenvector */
							Aux = 1.0 / sqrt(SymmNorm);
							for (j=0; j < PrimNum; ++j)
							{
								Unitary[Element(i,j)] = Aux * SymmVec[j];
							}
						}
						else
						{
						/* Dominant Antisymmetric Part:  Antisymmetrize Eigenvector */
							Aux = 1.0 / sqrt(AntiNorm);
							for (j=0; j < PrimNum; ++j)
							{
								Unitary[Element(i,j)] = Aux * AntiVec[j];
							}
						}
					}

				/* Free Memory */
					delete[] SymmVec;
					delete[] AntiVec;
				}

			/* Establish Error in Spectral Decomposition:  Q^+ Q = E, Q^+ Diag Q = A */
				if (CheckAccuracy == true)
				{
				/* On-Screen Message */
					cerr << "Checking accuracy of transformation ";

					double DevE = 0.0;
					double DevA = 0.0;

				/* Matrix Multiplication (only upper diagonal part) */
					for (i = 0; i < MatrixDim; ++i)
					{
						for (j = i; j < MatrixDim; ++j)
						{
						/* Prepare Element of Identity Matrix */
							double SumE = 0.0;
							if (i == j)  SumE = 1.0;

						/* Prepare Element of Original Rate Matrix */
							double SumA = SymmMatrCopy[Element(i,j)];

						/* Pointer in Matrix */
							long Ptr = 0;

							for (l = 0; l < MatrixDim; ++l)
							{
								Aux = Unitary[Ptr + i] * Unitary[Ptr + j];
								Ptr += PrimNum;

								SumE -= Aux;
								SumA -= Aux * Diag[l];
							}

						/* Square Deviation From Identity Matrix */
							Aux = SumE * SumE;
							DevE += Aux;

						/* Off-Diagonal Elements Have Double Weight */
							if (i != j)  DevE += Aux;

						/* Square Deviation From Original Rate Matrix */
							Aux = SumA * SumA;
							DevA +=  Aux;
						/* Off-Diagonal Elements Have Double Weight */
							if (i != j)  DevA += Aux;
						}

					/* Progress */
						cerr << ".";
					}

				/* Deliver Schur (L2) Matrix Norm */
					Info << "Accuracy of diagonalization (momentum subspace q = 0):\n"
						 << "Schur norm of Q^+ Q - E     : " << sqrt(DevE) << "\n"
						 << "Schur norm of Q^+ Diag Q - A: " << sqrt(DevA) << "\n\n";

				/* Cleanup */
					delete[] SymmMatrCopy;
					cerr << " done.\n";
				}
			}

			cerr << "\n";
		}

	/* *** THE NONZERO MOMENTUM SUBSPACES *** */

	/* Temporary Storage For Unitary Transformation Only Required For QSubspace > 0 */
		complex<double> *qNonZero;
		complex<double> *SupDiag;
		complex<double> *HermMatrCopy;

		if ((SingleQSubspace == false) || ((QSubspace % p) != 0))
		{
			qNonZero	= new complex<double>[PrimNum * PrimNum];

		/* Verify Successful Allocation of Memory */
			if (qNonZero == 0)  ErrorMessage("Insufficient Memory");

		/* Temporary Storage For Superdiagonal Elements */
			SupDiag = new complex<double>[PrimNum];

		/* Reserve Storage For Testing Purposes, If Required */
			if (CheckAccuracy == true)
			{
			/* Assign Storage */
				HermMatrCopy = new complex<double>[PrimNum * PrimNum];
			/* Verify Successful Allocation of Memory */
				if (HermMatrCopy == 0)  ErrorMessage("Insufficient Memory");
			}
		}

	/* Complex Momentum Shift */
		long m = ModuloDiv(1, k);

	/* Create Nonzero Momentum Submatrices */
	/* Establish Limits */
		int QMin = 1;
		int QMax = (p - 1) / 2;

		if (SingleQSubspace == true)
		{
			QMin = QSubspace;
			QMax = QSubspace;
		}

	/* Perform Iteration, If Necessary */
		for (q = QMin; q <= QMax; ++q)
		{
		/* Exclude q = 0 Subspace */
			if ((q % p)	== 0) continue;

			cerr << "Creating submatrix for momentum q = " << q << " ... ";

		/* Prefactors
			(first correct strange behavior of modulo operator if q is negative) */
			i = ((m * q) % p);
			if (i < 0) i += p;

			complex<double> BackwardRoot = UnityRoot[i];
			complex<double> ForwardRoot  = UnityRoot[p - i];

		/* Appropriate Offsets for Vectors, Matrices */
			long OffsetV = 0;
			long OffsetM = 0;
			if (SingleQSubspace == false)
			{
				OffsetV = q * PrimNum;
				OffsetM = OffsetV * PrimNum;
			}

		/* Fill Submatrix with Momentum q */
			for (i=0; i < PrimNum; ++i)
			{
				for (j=0; j < PrimNum; ++j)
				{
				/* Allowed Forward Shifts */
					qNonZero[Element(i,j)] = ForwardRoot *
						(RateA * Forward[Element(i,j)].RateCoeffA +
						RateB * Forward[Element(i,j)].RateCoeffB +
						RateC * Forward[Element(i,j)].RateCoeffC +
						RateD * Forward[Element(i,j)].RateCoeffD);

				/* Allowed Backward Shifts */
					qNonZero[Element(i,j)] += BackwardRoot *
						(RateA * Backward[Element(i,j)].RateCoeffA +
						RateB * Backward[Element(i,j)].RateCoeffB +
						RateC * Backward[Element(i,j)].RateCoeffC +
						RateD * Backward[Element(i,j)].RateCoeffD);
				}

			/* Subtract Loss Terms */
				qNonZero[Element(i,i)] -= complex<double>(
					RateA * Diagonal[i].RateCoeffA
					+ RateB * Diagonal[i].RateCoeffB
					+ RateC * Diagonal[i].RateCoeffC
					+ RateD * Diagonal[i].RateCoeffD, 0.0);
			}

		/* Symmetrization Procedure */
			for (i=0; i < PrimNum; ++i)
			{
				for (j=i+1; j < PrimNum; ++j)
				{
					qNonZero[Element(i,j)] *= sqrt(EqEV[j] / EqEV[i]);
					qNonZero[Element(j,i)] = conj(qNonZero[Element(i,j)]);
				}
			}

			cerr << "done.\n";

		/* Make a Copy For Testing Purposes, If Required */
			if (CheckAccuracy == true)
			{
				for (i=0; i < PrimNum; ++i)
				{
					for (j=0; j < PrimNum; ++j)
					{
						HermMatrCopy[Element(i,j)] = qNonZero[Element(i,j)];
					}
				}
			}

		/* Successive Tridiagonalization and Diagonalization of Submatrix */
			cerr << "Diagonalizing submatrix for momentum q = " << q << ":\n\n";

			HouseholderHerm(&qNonZero[0], &Diag[OffsetV], &SupDiag[0]);
			QRHerm(&qNonZero[0], &Diag[OffsetV], &SupDiag[0]);

		/* Operations On Unitary Transformation Matrix */
			if (EigenvaluesOnly == false)
			{
			/* Remove Random Common Phases From Eigenvectors */
				for (i=0; i < PrimNum; ++i)
				{
					RemoveCommonPhase(&qNonZero[Element(i,0)]);
				}

			/* Encode Transformation Matrix Elements Into Unitary Storage */
				for (i=0; i < PrimNum; ++i)
				{
					for (j=0; j < PrimNum; ++j)
					{
					/* Palindromic Patterns - Real Element */
						if (j == MirrorImage[j])
						{
							Unitary[OffsetM + Element(i,j)] =
								real(qNonZero[Element(i,j)]);

						/* Adapt Unitary Matrix For Testing Purposes */
							qNonZero[Element(i,j)] =
								complex<double>(Unitary[OffsetM + Element(i,j)], 0.0);
						}
						else
						{
							if (j < MirrorImage[j])
							{
							/* Leading Element of Symmetric Pair in List - Real Part */
								Unitary[OffsetM + Element(i,j)] = 0.5 *
									(real(qNonZero[Element(i,j)])
									+ real(qNonZero[Element(i,MirrorImage[j])]));
							}
							else
							{
							/* Trailing Element of Symmetric Pair in List - Imag. Part */
								Unitary[OffsetM + Element(i,j)] = 0.5 *
									(imag(qNonZero[Element(i,j)])
									- imag(qNonZero[Element(i,MirrorImage[j])]));

							/* Adapt Unitary Matrix For Testing Purposes */
								qNonZero[Element(i,j)] = complex<double>
									(Unitary[OffsetM + Element(i,MirrorImage[j])],
									 Unitary[OffsetM + Element(i,j)]);
								qNonZero[Element(i,MirrorImage[j])] =
									conj(qNonZero[Element(i,j)]);
							}
						}
					}
				}

			/* Establish Error in Spectral Decomposition:  Q^+ Q = E, Q^+ Diag Q = A */
				if (CheckAccuracy == true)
				{
				/* On-Screen Message */
					cerr << "Checking accuracy of transformation ";

					double DevE = 0.0;
					double DevA = 0.0;

				/* Matrix Multiplication (only upper diagonal part) */
					for (i = 0; i < MatrixDim; ++i)
					{
						for (j = i; j < MatrixDim; ++j)
						{
						/* Prepare Element of Identity Matrix */
							complex<double> SumE = complex<double>(0.0, 0.0);
							if (i == j)  SumE = complex<double>(1.0, 0.0);

						/* Prepare Element of Original Rate Matrix */
							complex<double> SumA = HermMatrCopy[Element(i,j)];

						/* Pointer in Matrix */
							long Ptr = 0;

							for (l = 0; l < MatrixDim; ++l)
							{
								AuxC = conj(qNonZero[Ptr + i])	* qNonZero[Ptr + j];
								SumE -= AuxC;
								SumA -= AuxC * Diag[OffsetV + l];

								Ptr += PrimNum;
							}

						/* Square Deviation From Identity Matrix */
							Aux = norm(SumE);
							DevE += Aux;
						/* Off-Diagonal Elements Have Double Weight */
							if (i != j)  DevE += Aux;

						/* Square Deviation From Original Rate Matrix */
							Aux = norm(SumA);
							DevA += Aux;
						/* Off-Diagonal Elements Have Double Weight */
							if (i != j)  DevA += Aux;
						}

						cerr << ".";
					}

				/* Deliver Schur (L2) Matrix Norm */
					Info << "Accuracy of diagonalization"
						 << "(momentum subspace q = " << q << "):\n"
						 << "Schur norm of Q^+ Q - E     : " << sqrt(DevE) << "\n"
						 << "Schur norm of Q^+ Diag Q - A: " << sqrt(DevA) << "\n\n";

					cerr << " done.\n";
				}
			}

			cerr << "\n";
		}

	/* Destroy Unitary Matrix, Superdiagonal Elements, If Required */
		if ((SingleQSubspace == false) || (QSubspace > 0))
		{
			delete[] qNonZero;
			delete[] SupDiag;

		/* Destroy Copy of Rate Matrix, If Required */
			if (CheckAccuracy == true)
				delete[] HermMatrCopy;
		}
	}

/* Delete Symbolic Rate Coefficient Matrices */
	delete[] Diagonal;
	delete[] Forward;
	delete[] Backward;

/* Store the Transformation Data on Disk, If Desired */
	if (SaveBlockData == true)
	{
		cerr << "Saving block data on disk ... ";

	/* Check Validity of Transformation Matrix Filename */
		ofstream BlockSave(BlockFilename.c_str(), ios::binary);
		if (!BlockSave)
			ErrorMessage("Could Not Open Block Data File");

	/* Write Parameter Set */
		BlockSave.write((char *)&p, sizeof p);
		BlockSave.write((char *)&k, sizeof k);

		BlockSave.write((char *)&RateA, sizeof RateA);
		BlockSave.write((char *)&RateB, sizeof RateB);
		BlockSave.write((char *)&RateC, sizeof RateC);
		BlockSave.write((char *)&RateD, sizeof RateD);

	/* Save Block Data */

	/* Save Eigenvalues */
		BlockSave.write((char *)&Diag[0], (p+1) * PrimNum * sizeof(double) / 2);
	/* Save Unitary Matrix Data */
		BlockSave.write((char *)&Unitary[0],
		                (p+1) * PrimNum * PrimNum * sizeof(double) / 2);

	/* Cleanup */
		BlockSave.close();

		cerr << "done.\n\n";
	}


/* *** OUTPUT OF EIGENVALUES/EIGENVECTORS *** */

/* Ordered Output of Eigenvalues, If Desired */

/* Pointer Storage Template */
	long *EigenPtr;

	if (ShowEigenvalues == true)
	{
	/* Provide Storage For Pointers */
		if (SingleQSubspace == false)
			EigenPtr = new long[PrimNum * (p+1) / 2];
		else
			EigenPtr = new long[PrimNum];

	/* Verify Successful Allocation of Memory */
		if (EigenPtr == 0)  ErrorMessage("Insufficient Memory");

	/* Storage for Single-Site Projector in q-Space */
		complex<double> *QProj = new complex<double> [PrimNum];

	/* Sorting of Eigenvalues */
		cerr << "Sorting eigenvalues ... ";

	/* Sort Momentum Subspaces */
		if (SingleQSubspace == false)
		{
			for (q=0; q <= (p-1)/2; ++q)
			{
				EigenSort(&Diag[q * PrimNum], &EigenPtr[q * PrimNum]);
			}
		}
		else
		{
			EigenSort(&Diag[0], &EigenPtr[0]);
		}

		cerr << "done.\n\n";

	/* Zero Momentum Subspace */
		if ((SingleQSubspace == false) || ((QSubspace % p) == 0))
		{
			Info << "Eigenvalues with momentum q = 0:\n\n";

			for (i = PrimNum; i>0; --i)
			{
				Info << "Eigenvalue #" << (PrimNum - i)
				     << ": \t" << Diag[EigenPtr[i-1]] << " \t";

			/* Show Eigenvector Properties, If Possible */
				if (EigenvaluesOnly == true)
				{
					Info << "\n";
				}
				else
				{
				/* Indicate Whether Eigenvector is (Anti-)Symmetric */
					bool Symm = VectorIsSymmetric(&Unitary[Element(EigenPtr[i-1],0)]);
					bool Anti = VectorIsAntisymmetric(&Unitary[Element(EigenPtr[i-1],0)]);

					if (Symm == true)
					{
						Info << "[symmetric]\n";
					}
					else
					{
						if (Anti == true)
						{
							Info << "[antisymmetric]\n";
						}
						else
						{
							Info << "[mixed symmetry]\n";
						}
					}

				/* Determine Eigenvectors and their Contribution to <q=0> */
					double Overlap = 0.0;

					for (j=0; j < PrimNum; ++j)
					{
						Aux = Unitary[Element(EigenPtr[i-1],j)];

					/* Add Projection Component for EV of Unsymmetrized Matrix R(q) */
						if (ShowQContribution == true)
							Overlap += k * sqrt(EqEV[j] / p) * Aux;

					/* Output Eigenvector Data, If Desired */
						if (ShowEigenvectors == true)
						{
						/* Modify If Eigenvectors of Unsymmetrized Matrix R(0) Desired */
							if (ShowLeftEV  == true)  Aux *= sqrt(p / EqEV[j]);
							if (ShowRightEV == true)  Aux *= sqrt(EqEV[j] / p);

							Info << "\t" << j << " --- " << Aux << "\n";
						}
					}

				/* Show Contribution of Eigenvector to Single-Site Average <q=0>, If Desired */
					if (ShowQContribution == true)
						Info << "\n\tContribution to <q=0>: " << Overlap;

				/* Show Weight of Eigenvector in Expansion of Initial State, If Desired */
					if (ShowEVWeight == true)
					{
					/* Project Initial State on Eigenstate - Zero Momentum */
						Aux = Unitary[Element(EigenPtr[i-1],State)] / sqrt(p * EqEV[State]);
						Info << "\n\tWeight in Initial Configuration: " << Aux;
					}

					Info << "\n\n";
				}
			}


		/* Eigenvalue in One-Particle Diffusion */
			Info << "(One-particle diffusion: EV = 0)\n\n";
		}

	/* Nonzero Momentum Subspaces */
	/* Select Proper Range */
		int QMin = 1;
		int QMax = (p - 1) / 2;
		if (SingleQSubspace == true)
		{
			QMin = QSubspace;
			QMax = QSubspace;
		}

		for (q=QMin; q <= QMax; ++q)
		{
		/* Disregard q = 0 Subspace */
			if ((q % p) == 0)  continue;

			Info << "Eigenvalues with momentum q = " << q << ":\n\n";

		/* Proper Offsets into Matrices */
			long OffsetV = 0;
			long OffsetM = 0;
			if (SingleQSubspace == false)
			{
				OffsetV = q * PrimNum;
			   OffsetM = OffsetV * PrimNum;
			}

			for (i = PrimNum; i>0; --i)
			{
				Info << "Eigenvalue #" << (PrimNum - i) << ": \t"
					<< Diag[OffsetV + EigenPtr[OffsetV + i - 1]] << "\n";

				if (EigenvaluesOnly == false)
				{
				/* Pointer to Eigenvector */
					long Ptr = OffsetM + PrimNum * EigenPtr[OffsetV + i - 1];

				/* Calculate Projection Vector for Single-Site Average <q> */
					if (ShowQContribution == true)
					{
					/* Determine Projection Vector */
						for (j=0; j < PrimNum; ++j)
						{
							QProj[j] = complex<double>(0.0, 0.0);

						/* Sum Over Occupied Sites */
							for (nu=0; nu < p; ++nu)
							{
								if ((Primitive[j].Code & exp2pow[nu]) > 0)
								{
									QProj[j] += UnityRoot[(q * nu) % p];
								}
							}
						}
					}

				/* Form Eigenvectors, Projection on <q> */
					double Overlap = 0.0;

					for (j=0; j < PrimNum; ++j)
					{

					/* Recompose Eigenvector */
						if (j == MirrorImage[j])
						{
						/* Palindromic Pattern - Real Element */
							AuxC = complex<double>(Unitary[Ptr + j], 0.0);
						}
						else
						{
						/* Mirror Symmetric Pair of Patterns */
							if (j < MirrorImage[j])
							{
								AuxC = complex<double>
										(Unitary[Ptr + j], Unitary[Ptr + MirrorImage[j]]);
							}
							else
							{
								AuxC = complex<double>
									(Unitary[Ptr + MirrorImage[j]], -Unitary[Ptr + j]);
							}
						}

					/* Add Projection Component for EV of Unsymmetrized Matrix R(q) */
						if (ShowQContribution == true)
						{
							Overlap += real(conj(QProj[j]) * AuxC) * sqrt(EqEV[j] / p);
						}

					/* Show Elements of Eigenvector, If Desired */
						if (ShowEigenvectors == true)
						{
						/* Modify If Eigenvectors of Unsymmetrized Matrix R(q) Desired */
							if (ShowLeftEV  == true)  AuxC = conj(AuxC) * sqrt(p / EqEV[j]);
							if (ShowRightEV == true)  AuxC *= sqrt(EqEV[j] / p);

							Info << "\t" << j << " --- " << AuxC << "\n";
						}
					}

				/* Show Contribution of Eigenvector to Single-Site Average <q>, If Desired */
					if (ShowQContribution == true)
						Info << "\n\tContribution to <q=" << q << ">: " << Overlap;

				/* Show Weight of Eigenvector in Expansion of Initial State, If Desired */
					if (ShowEVWeight == true)
					{
					/* Project Initial State on Eigenstates - Nonzero Momentum */

					/* Prefactor */
						AuxC = UnityRoot[p - ((Shift * q) % p)] / sqrt(p * EqEV[State]);

					/* Extract Unitary Transformation Matrix Element and Multiply */
						if (State == MirrorImage[State])
						{
						/* Palindromic State */
							AuxC *= Unitary[OffsetM + Element(EigenPtr[OffsetV + i - 1],State)];
						}
						else
						{
						/* Extract Real And Imaginary Parts */
							if (State < MirrorImage[State])
							{
							/* Element Contains Real Part */
								AuxC *= complex<double>
										(Unitary[OffsetM + Element(EigenPtr[OffsetV + i - 1],State)],
										-Unitary[OffsetM + Element(EigenPtr[OffsetV + i - 1],
																							MirrorImage[State])]);
							}
							else
							{
							/* Element Contains Imaginary Part */
								AuxC *= complex<double>
										(Unitary[OffsetM + Element(EigenPtr[OffsetV + i - 1],
																							MirrorImage[State])],
								 		Unitary[OffsetM + Element(EigenPtr[OffsetV + i - 1],State)]);
							}
						}

						Info << "\n\tWeight in Initial Configuration: " << real(AuxC);

						if (imag(AuxC) != 0.0)
						{
							if (imag(AuxC) > 0.0)  Info << " + " <<  imag(AuxC) << "i";
							else						  Info << " - " << -imag(AuxC) << "i";
						}
						Info << "\n\n";
					}

					Info << "\n";
				}
			}

		/* Eigenvalue in One-Particle Diffusion */
			double EV = - 4.0 * RateA * sin(q * Pi / p) * sin(q * Pi / p);
			Info  << "(One-particle diffusion: EV = " << EV << ")\n\n";
		}

	/* Destroy Pointer, Vector Arrays */
		delete[] EigenPtr;
		delete[] QProj;
	}


/* *** EVOLUTION OF A PURE INITIAL STATE (IF DESIRED) *** */

	if ((Evolution == true) || (EquilibriumAverage == true))
	{

	/* Write Opening Message */
		Data << "# DIFFUSION.c++ - Diffusion on a Circle - Canonical Ensemble\n"
			 << "# (Version " << VersionSpec << ", written " << VersionDate << ")\n"
			 << "# Author:  Christian Bracher\n"
			 << "# \n";

	/* Write Information Into Data File */
		Data << "# Evolution of the state " << InitState.Graphics() << "\n"
			 << "# (" << k << " atoms on " << p << " sites)\n"
			 << "# \n"
			 << "# (for additional information, see the file "
			 << InfoFilename.c_str() << ")\n"
			 << "# \n";

	/* Write Averaging Pattern/Equilibrium Information Information */
		Data << "# Column 0: \tTime\n";
		for (i=0; i < AveragePatternNumber; ++i)
		{
			Data << "# Column " << i+1 << ": \t<" << AveragePattern[i] << ">";
		/* Add Equilibrium Averages, If Desired */
			if ((EquilibriumAverage == true) || (ShowDeviation == true))
			{
				Data << " \t(equilibrium average: "
				     << EqAverage(AveragePattern[i]) << ")";
			}
			Data << "\n";
		}
		Data << "# \n";

	/* Indicate Type of Data */
		if (ShowDeviation == true)
		{
			Data << "# Deviation of averages from equilibrium occupation: \n";
		}
		else
		{
			Data << "# Average occupation data: \n";
		}
		Data << "# \n";

	/* Calculate the Evolution of the Initial State, If Desired */
		if (Evolution == true)
		{
		/* Find Matching Patterns */
			cerr << "Creating Pattern Match Information ... ";

		/* Create Boolean Pattern Matching Flag Field */
			DoesMatch = new bool[AveragePatternNumber * PrimNum * p];

		/* Verify Successful Allocation of Memory */
			if (DoesMatch == 0)
			{
				cerr << "\n\n";
				ErrorMessage("Insufficient Memory");
			}

		/* Assign Flags */
			long Counter = 0;
			for (i=0; i < AveragePatternNumber; ++i)
			{
				for (j=0; j < PrimNum; ++j)
				{
					for (nu=0; nu < p; ++nu)
					{
						DoesMatch[Counter] = Primitive[j].Match(AveragePattern[i]);

						++Primitive[j];
						++Counter;
					}
				}
			}

			cerr << "done.\n";

		/* Identify Equilibrium Eigenvector In Zero Momentum Subspace */
			long EqEVIndex;
			double EqEVValue = -1.0;

			for (i=0; i < PrimNum; ++i)
			{
				if (Diag[i] > EqEVValue)
				{
					EqEVValue = Diag[i];
					EqEVIndex = i;
				}
			}

		/* Start Calculation */
			cerr << "Calculating evolution of the initial state ";

		/* Auxiliary Vectors */
			double *InitialZeroVec = new double[PrimNum];
			complex<double> *InitialNonZeroVec = new complex<double>[(p-1) * PrimNum / 2];

			double *IntermediateZeroVec = new double[PrimNum];
			complex<double> *IntermediateNonZeroVec =
				new complex<double>[(p-1) * PrimNum / 2];

			double *FinalZeroVec = new double[PrimNum];
			complex<double> *FinalNonZeroVec = new complex<double>[(p-1) * PrimNum / 2];

		/* Storage for Result */
			double *ResultVec = new double[p * PrimNum];

		/* Verify Successful Allocation of Memory */
			if (ResultVec == 0)
			{
				cerr << "\n\n";
				ErrorMessage("Insufficient Memory");
			}

		/* Project Initial State on Eigenstates - Zero Momentum */
			Aux = 1.0 / sqrt(p * EqEV[State]);

			for (i=0; i < PrimNum; ++i)
			{
				InitialZeroVec[i] = Aux * Unitary[Element(i,State)];
			}

		/* Project Initial State on Eigenstates - Nonzero Momentum */
			for (q=1; q <= (p-1) / 2; ++q)
			{
			/* Offsets in Vector/Matrix */
				long OffsetV = (q-1) * PrimNum;
				long OffsetM = q * PrimNum * PrimNum;

			/* Prefactor */
				AuxC = UnityRoot[p - ((Shift * q) % p)] / sqrt(p * EqEV[State]);

				for (i=0; i < PrimNum; ++i)
				{
				/* Extract Unitary Transformation Matrix Element and Multiply */
					if (State == MirrorImage[State])
					{
					/* Palindromic State */
						InitialNonZeroVec[OffsetV + i] =
							AuxC * Unitary[OffsetM + Element(i,State)];
					}
					else
					{
					/* Extract Real And Imaginary Parts */
						if (State < MirrorImage[State])
						{
						/* Element Contains Real Part */
							InitialNonZeroVec[OffsetV + i] = AuxC * complex<double>
									(Unitary[OffsetM + Element(i,State)],
									-Unitary[OffsetM + Element(i,MirrorImage[State])]);
						}
						else
						{
						/* Element Contains Imaginary Part */
							InitialNonZeroVec[OffsetV + i] = AuxC * complex<double>
									(Unitary[OffsetM + Element(i,MirrorImage[State])],
									 Unitary[OffsetM + Element(i,State)]);
						}
					}
				}
			}


		/* *** TEMPORAL EVOLUTION OF INITIAL STATE *** */

		/* Select Proper Timestep */
			double TimeStep;

			if (LogScale == false)
			{
			/* Linear Evolution */
				TimeStep = (StopTime - StartTime) / Steps;
			}
			else
			{
			/* Logarithmic Evolution */
				TimeStep = pow(StopTime / StartTime, 1.0 / Steps);
			}

		/* Time of Evolution */
			double Time = StartTime;

		/* Temporal Evolution */
			for (l=0; l <= Steps; ++l)
			{
			/* Weigh Eigenstates by Individual Decay Rates - Zero Momentum */
				for (i=0; i < PrimNum; ++i)
				{
				/* Check for Equilibrium Eigenvalue */
					if (i == EqEVIndex)
					{
					/* Special Treatment of Equilibrium Eigenvalue */
						if (ShowDeviation == true)
						{
						/* Deviation from Average: Ignore Contribution */
							IntermediateZeroVec[i] = 0.0;
						}
						else
						{
						/* Full Average:  No Temporal Dependence
						   (eliminate roundoff error) */
							IntermediateZeroVec[i] = InitialZeroVec[i];
						}
					}
					else
					{
					/* Standard Exponential Decay */
						IntermediateZeroVec[i] = exp(Diag[i] * Time) * InitialZeroVec[i];
					}
				}

			/* Weigh Eigenstates by Individual Decay Rates - Nonzero Momentum */
				for (q=1; q <= (p-1) / 2; ++q)
				{
				/* Offset in Vector */
					long OffsetV = (q-1) * PrimNum;

					for (i=0; i < PrimNum; ++i)
					{
						IntermediateNonZeroVec[OffsetV + i] =
							exp(Diag[OffsetV + PrimNum + i] * Time)
							* InitialNonZeroVec[OffsetV + i];
					}
				}

			/* Projection on Final Momentum States - Zero Momentum */
				for (i=0; i < PrimNum; ++i)
				{
				/* Initialize */
					FinalZeroVec[i] = 0.0;

					for (j=0; j < PrimNum; ++j)
					{
					/* Matrix Multiplication with Transpose of Q */
						FinalZeroVec[i] += sqrt(EqEV[i] / p) * Unitary[Element(j,i)]
						                   * IntermediateZeroVec[j];
					}
				}

			/* Projection on Final Momentum States - Nonzero Momentum */
				for (q=1; q <= (p-1) / 2; ++q)
				{
				/* Offsets in Vector/Matrix */
					long OffsetV = (q-1) * PrimNum;
					long OffsetM = q * PrimNum * PrimNum;

					for (i=0; i < PrimNum; ++i)
					{
					/* Initialize */
						FinalNonZeroVec[OffsetV + i] = 0.0;

						for (j=0; j < PrimNum; ++j)
						{
						/* Matrix Multiplication with Conjugate of Q */
							AuxC = sqrt(EqEV[i] / p) * IntermediateNonZeroVec[OffsetV + j];

						/* Extract Unitary Transformation Matrix Element and Multiply */
							if (i == MirrorImage[i])
							{
							/* Palindromic State */
								AuxC *= Unitary[OffsetM + Element(j,i)];
							}
							else
							{
							/* Extract Real And Imaginary Parts */
								if (i < MirrorImage[i])
								{
								/* Element Contains Real Part */
									AuxC *= complex<double>
											(Unitary[OffsetM + Element(j,i)],
											 Unitary[OffsetM
											         + Element(j,MirrorImage[i])]);
								}
								else
								{
								/* Element Contains Imaginary Part */
									AuxC *= complex<double>
											(Unitary[OffsetM + Element(j,MirrorImage[i])],
											-Unitary[OffsetM + Element(j,i)]);
								}
							}

							FinalNonZeroVec[OffsetV + i] += AuxC;
						}
					}
				}

			/* Translation Into Physical Result Vector */
				for (i = 0; i < PrimNum; ++i)
				{
				/* Loop Through Primitive Patterns */
					for (nu = 0; nu < p; ++nu)
					{
					/* Loop Through Shifts of this Pattern and Initialize */
						ResultVec[nu * PrimNum + i] = FinalZeroVec[i];

						for (q = 1; q <= (p-1) / 2; ++q)
						{
						/* Loop Through Nonzero Momentum Contributions */
							ResultVec[nu * PrimNum + i] += 2.0 * real(
								UnityRoot[(q * nu) % p]
								* FinalNonZeroVec[(q-1) * PrimNum + i]);
						}
					}
				}

			/* Calculate and Output Desired Averages */
				Data << Time << " \t";

			/* Loop Over Comparison Patterns */
				Counter = 0;
				for (i = 0; i < AveragePatternNumber; ++i)
				{
					Aux = 0.0;

				/* Loop Over Primitive Patterns */
					for (j=0; j < PrimNum; ++j)
					{
					/* Loop Over All Possible Rotations */
						for (nu=0; nu < p; ++nu)
						{
						/* Only Matching Patterns Contribute */
							Aux += (int)DoesMatch[Counter] * ResultVec[nu * PrimNum + j];
							++Counter;
						}
					}

				/* For Raw Averages:  Remove Spurious Signs Caused by Rounding Errors */
					if (ShowDeviation == false)
					{
						if (Aux < 0.0)  (Aux = 0.0);
					}

				/* Output Average Data */
					Data << Aux << " \t";
				}

				Data << "\n";

			/* Advance Time, Indicate Progress */
				if (LogScale == false)
				{
				/* Linear Evolution */
					Time += TimeStep;
				}
				else
				{
				/* Logarithmic Evolution */
					Time *= TimeStep;
				}

				cerr << ".";
			}

			cerr << " done.\n\n";

		/* Free Allocated Memory */
			delete[] InitialZeroVec;
			delete[] InitialNonZeroVec;
			delete[] IntermediateZeroVec;
			delete[] IntermediateNonZeroVec;
			delete[] FinalZeroVec;
			delete[] FinalNonZeroVec;
			delete[] ResultVec;
			delete[] DoesMatch;
		}
	}


/* *** CLEAN-UP AND FINISH *** */

	Info.close();
	Data.close();

	delete[] Diag;
	delete[] Unitary;

	delete[] EqEV;

	delete[] Primitive;
	delete[] MirrorImage;
	delete[] AveragePattern;

	delete[] exp2pow;
	delete[] UnityRoot;

	return 0;
}

Diffusion on a Ring
===================

Diffusion of interacting atoms along a ring of sites (research project)

### Overview

This project arose from a problem in statistical physics, the diffusion of interacting adsorbate atoms on a surface.  As the full problem is hard to attack in an analytic fashion, I chose to study a simpler "toy problem", the hopping diffusion of objects along a one dimensional ring of sites.  Starting from a set of rules for the interaction of atoms on neighboring sites, I set up a master equation that governs the evolution of the probability to find a particular pattern of occupied sites at a given time, and recast the issue as an eigenvalue problem.  Due to the abundance of possible patterns, tackling the eigenvalue problem is a complex task even for a small number of atoms.

The code made available here, written in C++ as a console application, exploits symmetry aspects of the configuration to split the calculation into smaller independent problems, and solves them numerically.  It has complex functionality to control program flow and perform statistical operations on the output.  The accompanying documentation presents details regarding the many options available.

### Repository contents

The material has been organized into several folders:

* *C++ code*
  
  Contains 32-bit and 64-bit versions of the source code.  Due to the binary representation of atomic patterns, the 32-bit version can handle rings with up to 31 sites, while the 64-bit version extends this limit to 61 sites.  (The algebra underlying the mathematical approach restricts the number of sites to a prime number.)
  
* *Documentation*
  
  User manuals that explains basic notions, and detail the program options and switches available
  
* *Notes*
  
  Extensive notes regarding the underlying mathematics and physics of the algorithm and its implementation.
  
* *Example*
  
  Results for a few model calculations for 5 atoms on a ring of 19 sites, including graphical illustrations.
  
* *Presentation*
    
  A presentation explaining some of the aspects of the problem, and showcasing results generated with the code.
  
* *Publication*
    
  A peer-reviewed publication that illustrates the physical context, briefly explains the approach, and delivers some findings based on calculations with the program:
  
    *Hopping Kinetics on a Finite 1D Chain: An Exact Analysis*

    J.-S. McEwen, S. H. Payne, H. J. Kreuzer, C. Bracher
    
    *International Journal of Quantum Chemistry*, Vol. 106, 2889–2903 (2006)
    
  (See also references therein.)


#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Na_iFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Na_iFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, phi_Na_en );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Na_iFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, phi_Na_en );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Na_c  = getVariableReference( "Na_c" ).getVariable();
    Na_i  = getVariableReference( "Na_i" ).getVariable();
    i_Na  = getVariableReference( "i_Na" ).getVariable();
    i_B_Na  = getVariableReference( "i_B_Na" ).getVariable();
    i_NaK  = getVariableReference( "i_NaK" ).getVariable();
    i_NaCa  = getVariableReference( "i_NaCa" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (i_Na->getValue()+i_B_Na->getValue()+3.00000*i_NaK->getValue()+3.00000*i_NaCa->getValue()+phi_Na_en)/F * N_A * 1.0e-12 );
  }

 protected:

  Variable* Na_c;
  Variable* Na_i;
  Variable* i_Na;
  Variable* i_B_Na;
  Variable* i_NaK;
  Variable* i_NaCa;

  Real phi_Na_en;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Na_iFluxProcess, Process );

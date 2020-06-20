
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_NaCaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_NaCaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );
    PROPERTYSLOT_SET_GET( Real, d_NaCa );
    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, k_NaCa );
    PROPERTYSLOT_SET_GET( Real, gamma );

  }

  Nygren_1998i_NaCaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );
  SIMPLE_SET_GET_METHOD( Real, d_NaCa );
  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, k_NaCa );
  SIMPLE_SET_GET_METHOD( Real, gamma );


  virtual void initialize()
  {
    Process::initialize();

    i_NaCa  = getVariableReference( "i_NaCa" ).getVariable();
    Na_i  = getVariableReference( "Na_i" ).getVariable();
    Ca_c  = getVariableReference( "Ca_c" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    Na_c  = getVariableReference( "Na_c" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    i_NaCa->setValue( 1 * ((k_NaCa*((pow((Na_i->getMolarConc()*1000), 3.00000))*(Ca_c->getMolarConc()*1000)*exp((gamma*F*V->getValue())/(R*T))-(pow((Na_c->getMolarConc()*1000), 3.00000))*(Ca_i->getMolarConc()*1000)*exp(((gamma-1.00000)*V->getValue()*F)/(R*T))))/(1.00000+d_NaCa*((pow((Na_c->getMolarConc()*1000), 3.00000))*(Ca_i->getMolarConc()*1000)+(pow((Na_i->getMolarConc()*1000), 3.00000))*(Ca_c->getMolarConc()*1000)))) );

  }

 protected:

  Variable* i_NaCa;
  Variable* Na_i;
  Variable* Ca_c;
  Variable* V;
  Variable* Na_c;
  Variable* Ca_i;

  Real F;
  Real d_NaCa;
  Real R;
  Real T;
  Real k_NaCa;
  Real gamma;

};

LIBECS_DM_INIT( Nygren_1998i_NaCaAssignmentProcess, Process );

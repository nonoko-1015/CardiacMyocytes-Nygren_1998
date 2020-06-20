
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Na_cFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Na_cFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, tau_Na );
    PROPERTYSLOT_SET_GET( Real, Na_b );

  }

  Nygren_1998j_Na_cFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, tau_Na );
  SIMPLE_SET_GET_METHOD( Real, Na_b );


  virtual void initialize()
  {
    Process::initialize();

    Na_c  = getVariableReference( "Na_c" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (Na_b-(Na_c->getMolarConc()*1000))/tau_Na * getSuperSystem()->getSizeN_A() / 1000 );
  }

 protected:

  Variable* Na_c;

  Real tau_Na;
  Real Na_b;

};

LIBECS_DM_INIT( Nygren_1998j_Na_cFluxProcess, Process );

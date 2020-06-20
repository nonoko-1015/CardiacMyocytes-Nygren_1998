
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_cFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_cFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, Ca_b );
    PROPERTYSLOT_SET_GET( Real, tau_Ca );

  }

  Nygren_1998j_Ca_cFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, Ca_b );
  SIMPLE_SET_GET_METHOD( Real, tau_Ca );


  virtual void initialize()
  {
    Process::initialize();

    Ca_c  = getVariableReference( "Ca_c" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (Ca_b-(Ca_c->getMolarConc()*1000))/tau_Ca * getSuperSystem()->getSizeN_A() / 1000 );
  }

 protected:

  Variable* Ca_c;

  Real Ca_b;
  Real tau_Ca;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_cFluxProcess, Process );

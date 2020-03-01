#include <ntddk.h>
#include <wdf.h>

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD kmdf_helloworld_evt_device_add;

NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
	//NTSTATUS variable to record success or failure
	NTSTATUS status = STATUS_SUCCESS;

	//Allocate the driver configuration object
	WDF_DRIVER_CONFIG config;

	//Print "Hello World" for DriverEntry
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n"));

	//Initialize the driver configuration object to register the entry point for the EvtDeviceAdd callback, KmdfHelloWorldEvtDeviceAdd
	WDF_DRIVER_CONFIG_INIT(&config,
		kmdf_helloworld_evt_device_add
	);

	//Finally, create the driver object
	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
	return status;
}

NTSTATUS
kmdf_helloworld_evt_device_add(
	_In_ WDFDRIVER Driver,
	_In_ PWDFDEVICE_INIT DeviceInit
)
{
	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;

	//Allocate the device object
	WDFDEVICE hDevice;

	//Print "Hello World"
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: kmdf_helloworld_evt_device_add\n"));

	//Create the device object
	status = WdfDeviceCreate(&DeviceInit,
		WDF_NO_OBJECT_ATTRIBUTES,
		&hDevice);
	return status;
}
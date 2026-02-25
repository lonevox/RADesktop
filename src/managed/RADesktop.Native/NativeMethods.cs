using System.Runtime.InteropServices;

namespace RADesktop.Native;

internal static class NativeMethods
{
    [DllImport("RADesktop.NativeCore.dll", CallingConvention = CallingConvention.Cdecl)]
    internal static extern int rd_ping();
}
